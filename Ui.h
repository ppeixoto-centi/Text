/* 
 * File:   Ui.h
 * Author: ppeixoto
 *
 * Created on 5 de Março de 2026, 13:46
 */

#ifndef UI_H
#define	UI_H

#ifdef	__cplusplus
extern "C" {
#endif

/* ************************************************************************************ */
/* * Includes                                                                         * */
/* ************************************************************************************ */

#include <stdbool.h>
#include <stdint.h>
       
/* ************************************************************************************ */
/* * Function Types                                                                         * */
/* ************************************************************************************ */

// Gpio set/get functions
typedef void (*Gpio_Set)(bool state);
typedef void (*Gpio_Toggle) (void);
typedef void (*Gpio_Clear) (void);
typedef bool (*Gpio_Get)(void);


/* ************************************************************************************ */
/* * Structs                                                                        * */
/* ************************************************************************************ */

typedef struct{
    Gpio_Set Led0_Set;
    Gpio_Set Led1_Set;
    Gpio_Set Led2_Set;
    Gpio_Set Led3_Set;
    
    Gpio_Toggle Led0_Toogle;
    
    Gpio_Get Sw1_GetPin; 
    Gpio_Get Sw2_GetPin; 
    
    Gpio_Clear SW1_Clear;
    
}st_Ui_config;

/* ************************************************************************************ */
/* * Enum                                                                             * */
/* ************************************************************************************ */

typedef enum {
    LED0,
    LED1,
    LED2,
    LED3,
}ui_leds;

/* ************************************************************************************ */
/* * Defines                                                                          * */
/* ************************************************************************************ */

//Led Defines 
#define LED_ON              (   true    )
#define LED_OFF             (   false   )

//Button Defines
#define BUTTON_PRESSED      (   0   )
#define BUTTON_UNPRESSED    (   1   )


/************************************************************************************* */
/* * ISR                                                                              * */
/* ************************************************************************************ */

/**
 * @brief Button SW1 external ISR handler.
 *
 * @param   None.
 *
 * @return  None.
 */
void Ui_ISR_SW1(void);

/**
 * @brief Button SW2 external ISR handler.
 *
 * @param   None.
 *
 * @return  None.
 */
void Ui_ISR_SW2(void);

/************************************************************************************* */
/* * Public Functions                                                                 * */
/* ************************************************************************************ */

/**
 * @brief Set the LED state.
 *
 * @param[in]   led     LED number (between 0 and 3).
 * @param[in]   state   LED state.
 *                      - LED_ON: Turn on;
 *                      - LED_OFF: Turn off.
 *
 * @return  None.
 */
void Ui_Initialize(st_Ui_config);

/**
 * @brief Set LED0 state.
 *
 * @param[in]   state   LED state.
 *                      - LED_ON: Turn on;
 *                      - LED_OFF: Turn off.
 * @param[in]   LED     lED to apply the state.
 *                      - LED0: Led D2;
 *                      - LED2: Led D3;
 *                      - LED3: Led D4;
 *                      - LED4: Led D5;
 *
 * @return  None.
 */
void Ui_Set_LedState(bool state, ui_leds led);

/**
 * @brief GET SW1 state.
 *
 * @param[out]   state   SW1 state.
 *                      - BUTTON_PRESSED: Button Pressed;
 *                      - BUTTON_UNPRESSED: Button Unpressed;
 *
 * @return  None.
 */
bool Ui_Sw1_GetButtonState(void);

/**
 * @brief GET SW2 state.
 *
 * @param[out]   state   SW2 state.
 *                      - BUTTON_PRESSED: Button Pressed;
 *                      - BUTTON_UNPRESSED: Button Unpressed;
 *
 * @return  None.
 */
bool Ui_Sw2_GetButtonState(void);

/**
 * @brief Button SW1 read pin state.
 *
 * @param   None.
 *
 * @return  None.
 */
void Ui_Sw1_ReadPin(void);

/**
 * @brief Button SW2 read pin state.
 *
 * @param   None.
 *
 * @return  None.
 */
void Ui_Sw2_ReadPin(void);

/**
 * @brief Toggle LED0 state.
 *
 * @param   None.
 *
 * @return  None.
 */
void Ui_Led0_Toggle(void);

/**
 * @brief Clear SW1 logged state.
 *
 * @param   None.
 *
 * @return  None.
 */
void Ui_SW1_Clear(void);


#ifdef	__cplusplus
}
#endif

#endif	/* UI_H */