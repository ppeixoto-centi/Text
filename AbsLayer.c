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
#include "Ui.h"
#include "MCC_Generated_Files/system/pins.h"
#include "MCC_Generated_Files/adc/adc.h"
#include "MCC_Generated_Files/timer/tmr0.h"
#include "mcc_generated_files/dac/dac1.h"
#include "mcc_generated_files/i2c_host/i2c1.h"
#include "mcc_generated_files/pwm/pwm5.h"
#include "mcc_generated_files/uart/uart1.h"
#include "mcc_generated_files/spi/spi1.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

/* ************************************************************************************ */
/* * Defines                                                                          * */
/* ************************************************************************************ */

#define I2C_address            (0x52 >> 1)
#define LR_ModelId_MS           0x01
#define LR_ModelId_LS           0x0F
#define LR_Module_Type_MS       0x10
#define LR_Module_Type_LS       0x10

/* ************************************************************************************ */
/* * Struct                                                                           * */
/* ************************************************************************************ */

typedef struct {
    uint16_t address;

    uint8_t sensor_id[2];
    uint8_t module_type[2];
    
    uint8_t data[2];
} st_sensor;

/* ************************************************************************************ */
/* * Global Variables                                                                 * */
/* ************************************************************************************ */

const char str[] = "Button Pressed\r"; 

adc_result_t adc_value = 0;


uint8_t period_elapsed = 0;
bool i2c_received = false;

/* ************************************************************************************ */
/* * Private Functions Prototypes                                                     * */
/* ************************************************************************************ */

static uint8_t UART_SendBuffer(char *);

static void Led0_SetState(bool);
static void Led1_SetState(bool);
static void Led2_SetState(bool);
static void Led3_SetState(bool);

static void Led0_Toggle(void);

static bool SW1_ReadPin(void);
static bool SW2_ReadPin(void);

/************************************************************************************* */
/* * Public Functions                                                                 * */
/* ************************************************************************************ */

void Abs_LayerInit(void){ 
    st_Ui_config config;
    
    //Connect the Ui API to the low level driver (led related)
    config.Led0_Set = Led0_SetState;
    config.Led1_Set = Led1_SetState;
    config.Led2_Set = Led2_SetState;
    config.Led3_Set = Led3_SetState;
    
    config.Led0_Toogle = Led0_Toggle;
    
    //Connect the Ui API to the low level driver (button related)
    config.Sw1_GetPin = SW1_ReadPin;
    config.Sw2_GetPin = SW2_ReadPin;
            
    //Initializes the Ui API
    Ui_Initialize(config);
    
    //Registers all callback for the peripherals 
    SW1_SetInterruptHandler(ExtISR_Handler); //Registers the ISR callback
    TMR0_PeriodMatchCallbackRegister(TIM0_EllapsedTimeCallback); //Registers the ISR callback
    ADC_ConversionDoneCallbackRegister(ADC_CompleteConversionCallback);
    I2C1_CallbackRegister(I2C1_CompleteReceive);

    SPI1_Close();
    CS_SetHigh();
    
    UART_SendBuffer("Press Button SW2, Application in Halt mode\n\r");
    printf("Polling mode send with printf\n\r");
    
    TMR0_Start();

    //Initial Polling to initial the main code
    while (Ui_Sw2_GetButtonState() != true){
        Ui_Sw2_ReadPin();
        
        if (period_elapsed == PERIOD_ELAPSED){
            period_elapsed = NPERIOD_ELAPSED;
            Ui_Led0_Toggle();
        }
    } 
    
    printf("Press SW1 To Increase Toggle Freq\n\r");
    
    //Activate PWM
    PWM5CON |= (0X1) << 7;
    
    printf("Change the resistance to change the btightness of LED_D3\n\r");
    
}

void Abs_Loop(void){
    uint8_t buffer[1];

    static st_sensor sensor = {
        .address = I2C_address,
        .sensor_id = {LR_ModelId_MS, LR_ModelId_LS},
        .module_type = {LR_Module_Type_MS, LR_Module_Type_LS},
        .data = {0, 0}

    };

    char out_buffer[20];
    if (period_elapsed == PERIOD_ELAPSED){ //Sets the time base for the toggle
        period_elapsed = NPERIOD_ELAPSED; //Clears the logged elapsed time
        
        LED_D2_Toggle();

    }
    
    if (Ui_Sw1_GetButtonState() == BUTTON_PRESSED){ //Checks for button clicks 
        Ui_SW1_Clear();
        UART_SendBuffer(str);
        Timer0_PeriodSet( (uint8_t)(Timer0_PeriodGet() / 2)); //Sets the time base for half 
        
    }
    
    ADC_ConversionStart();
    
    /*SPI1_Open(HOST_CONFIG);
    CS_SetLow();
    SPI1_BufferWrite(buffer, 2); 
    SPI1_BufferRead(buffer, 2); 
    
    sprintf(out_buffer, "MSB %d LSB %d\n\r", buffer[1], buffer[0]);
    UART_SendBuffer(out_buffer);
    
    SPI1_Close();*/
    
    i2c_received = false;

    I2C1_WriteRead(0x0052,
               sensor.sensor_id,
               2,
               buffer,
               1);

    while(!i2c_received);

    printf("I2C slave responded with %u", sensor.data[0]);
        
    CS_SetHigh();
}

void ExtISR_Handler(void){
    Ui_ISR_SW1();
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

void I2C1_CompleteReceive(void){
    i2c_received = true;
}

void putch(char c){
    UART1_Write(c);
    
    while (UART1_IsTxReady() != true);
    
}
/* ************************************************************************************ */
/* * Private Functions                                                                * */
/* ************************************************************************************ */

static uint8_t UART_SendBuffer(char *str_ptr){
    if(str_ptr == NULL)
        return 0;
    
    while (*str_ptr){
        while (UART1_IsTxDone() != true);
        UART1_Write(*str_ptr);
        str_ptr++;
        
    }
    
    return 1;
}

static void Led0_SetState(bool state){
    if (state)
        LED_D2_SetHigh();
    else
        LED_D2_SetLow();
    
}
static void Led1_SetState(bool state){
    if (state)
        LED_D3_SetHigh();
    else
        LED_D3_SetLow();
    
}
static void Led2_SetState(bool state){
    if (state)
        LED_D4_SetHigh();
    else
        LED_D4_SetLow();
    
}
static void Led3_SetState(bool state){
    if (state)
        LED_D5_SetHigh();
    else
        LED_D5_SetLow();
    
}

static bool SW1_ReadPin(void){
    if (SW1_GetValue() == 1)
        return false;
    
    return true;
    
}
static bool SW2_ReadPin(void){
    if (SW2_GetValue () == 1)
        return false;
    
    return true;
    
}

static void Led0_Toggle(void){
    LED_D2_Toggle();
    
}

/* -- End of file -- */