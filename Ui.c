/* 
 * File:   Ui.c
 * Author: ppeixoto
 *
 * Created on 5 de Março de 2026, 13:46
 */

/* ************************************************************************************ */
/* * Includes                                                                         * */
/* ************************************************************************************ */

#include "Ui.h"
#include "mcc_generated_files/system/pins.h"

/* ************************************************************************************ */
/* * Global Variables                                                                 * */
/* ************************************************************************************ */

/* UI configuration. */
static st_Ui_config ui_config = {};

/* Buttons states. */
static uint8_t UI_SW1_button_pressed    = false;
static uint8_t UI_SW2_button_pressed    = false;

/* ************************************************************************************ */
/* * ISR Functions                                                                    * */
/* ************************************************************************************ */

void Ui_ISR_SW1(void)
{
    UI_SW1_button_pressed = ui_config.Sw1_GetPin();
}

void Ui_ISR_SW2(void)
{
    UI_SW2_button_pressed = ui_config.Sw2_GetPin();
}

/* ************************************************************************************ */
/* * Public Functions                                                                 * */
/* ************************************************************************************ */

void Ui_Initialize(st_Ui_config config_struct){
    ui_config = config_struct;
    
    UI_SW1_button_pressed = ui_config.Sw1_GetPin();
    UI_SW2_button_pressed = ui_config.Sw2_GetPin();
    
    ui_config.Led0_Set(LED_OFF);
    ui_config.Led1_Set(LED_OFF);
    ui_config.Led2_Set(LED_OFF);
    ui_config.Led3_Set(LED_OFF);
}

bool Ui_Sw1_GetButtonState(void){
    return UI_SW1_button_pressed;
}

bool Ui_Sw2_GetButtonState(void){
    return UI_SW2_button_pressed;
}

void Ui_Set_LedState(bool state, ui_leds led){
    if(led < 0 || led > 3)
        return;
    
    Gpio_Set table[4];
    table[0] = ui_config.Led0_Set;
    table[1] = ui_config.Led1_Set;
    table[2] = ui_config.Led2_Set;
    table[3] = ui_config.Led3_Set;  
    
    table[led](state);
}

void Ui_Sw1_ReadPin(void){
    ui_config.Sw1_GetPin();
}

void Ui_Sw2_ReadPin(void){
    UI_SW2_button_pressed = ui_config.Sw2_GetPin();
}

void Ui_Led0_Toggle(void){
    ui_config.Led0_Toogle();
}

void Ui_SW1_Clear(void){
    UI_SW1_button_pressed = BUTTON_UNPRESSED;
}
/* -- End of file -- */
