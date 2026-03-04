/* 
 * File:   AbsLayer.c
 * Author: ppeixoto
 *
 * Created on March 4, 2026, 1:36 PM
 */


/* ************************************************************************************ */
/* * Includes                                                                         * */
/* ************************************************************************************ */

#include "AbsLayer.h"
#include "MCC_Generated_Files/system/pins.h"
#include "MCC_Generated_Files/adc/adc.h"
#include "MCC_Generated_Files/timer/tmr0.h"
#include "mcc_generated_files/dac/dac1.h"
#include "mcc_generated_files/pwm/pwm5.h"

/* ************************************************************************************ */
/* * Defines                                                                          * */
/* ************************************************************************************ */

/* ************************************************************************************ */
/* * Global Variables                                                                 * */
/* ************************************************************************************ */

adc_result_t adc_value = 0;

static uint8_t abs_button; //Stores the button state
uint8_t period_elapsed = 0;

/* ************************************************************************************ */
/* * Macros                                                                           * */
/* ************************************************************************************ */

/* ************************************************************************************ */
/* * Private Functions Prototypes                                                     * */
/* ************************************************************************************ */


/************************************************************************************* */
/* * Public Functions                                                                 * */
/* ************************************************************************************ */

void Abs_LayerInit(void){ 
    abs_button = BUTTON_UNPRESSED;
    SW1_SetInterruptHandler(ExtISR_Handler); //Registers the ISR callback
    TMR0_PeriodMatchCallbackRegister(TIM0_EllapsedTimeCallback); //Registers the ISR callback
    
    ADC_Initialize();
    ADC_ChannelSelect(ADC_CHANNEL_ANA0);
    
    ADC_ConversionDoneCallbackRegister(ADC_CompleteConversionCallback);
    ADC_ConversionDoneInterruptEnable();
    
    DAC1_Initialize();
    PWM5_Initialize();
 
    while (SW2_GetValue() != 0); //Initial Polling to initial the main codeS
}

void Abs_Loop(void){
    if (period_elapsed == PERIOD_ELAPSED){ //Sets the time base for the toggle
        period_elapsed = NPERIOD_ELAPSED; //Clears the logged elapsed time
        
        LED_D2_Toggle();
    }
    
    if (abs_button == BUTTON_PRESSED){ //Checks for button clicks 
        abs_button = BUTTON_UNPRESSED;
        Timer0_PeriodSet( (uint8_t)(Timer0_PeriodGet() / 2)); //Sets the time base for half 
    }
    
    ADC_ConversionStart();
}

void ExtISR_Handler(void){
    abs_button = SW1_GetValue();
}

void TIM0_EllapsedTimeCallback(void){
    period_elapsed = PERIOD_ELAPSED;
}

void ADC_CompleteConversionCallback(void){
    float percentage = 0;
    uint16_t with = 0;
    
    adc_value = ADC_ConversionResultGet();
    
    percentage =((float)adc_value * 99.0 / 4095.0);
    DAC1_SetOutput((uint8_t)percentage);

    with = (uint16_t)((percentage/ 100.0) * 633.0);
    
    PWM5_LoadDutyValue(with);
}

uint8_t Get_ButtonState(void){
    return abs_button;
}

/* ************************************************************************************ */
/* * Private Functions                                                                * */
/* ************************************************************************************ */