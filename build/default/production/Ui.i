# 1 "Ui.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 295 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Ui.c" 2
# 12 "Ui.c"
# 1 "./Ui.h" 1
# 19 "./Ui.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdbool.h" 1 3
# 20 "./Ui.h" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/musl_xc8.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3
# 26 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 1 3
# 133 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned __int24 uintptr_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef __int24 intptr_t;
# 164 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include\\c99/stdint.h" 2 3
# 21 "./Ui.h" 2






typedef void (*Gpio_Set)(_Bool state);
typedef _Bool (*Gpio_Get)(void);






typedef struct{
    Gpio_Set Led0_Set;
    Gpio_Set Led1_Set;
    Gpio_Set Led2_Set;
    Gpio_Set Led3_Set;

    Gpio_Get Sw1_GetPin;
    Gpio_Get Sw2_GetPin;

}st_Ui_config;





typedef enum {
    LED0,
    LED1,
    LED2,
    LED3,
}ui_leds;
# 83 "./Ui.h"
void Ui_Initialize(st_Ui_config);
# 99 "./Ui.h"
void Set_LedState(_Bool state, ui_leds led);
# 110 "./Ui.h"
_Bool Sw1_GetButtonState(void);
# 121 "./Ui.h"
_Bool Sw2_GetButtonState(void);
# 130 "./Ui.h"
void UI_ISR_SW1(void);
# 139 "./Ui.h"
void UI_ISR_SW2(void);
# 13 "Ui.c" 2






static st_Ui_config ui_config = {};


static uint8_t UI_SW1_button_pressed = 0;
static uint8_t UI_SW2_button_pressed = 0;





void UI_ISR_SW1(void)
{
    UI_SW1_button_pressed = ui_config.Sw1_GetPin();
}

void UI_ISR_SW2(void)
{
    UI_SW2_button_pressed = ui_config.Sw2_GetPin();
}





void Ui_Initialize(st_Ui_config config_struct){
    ui_config = config_struct;

    UI_SW1_button_pressed = ui_config.Sw1_GetPin();
    UI_SW2_button_pressed = ui_config.Sw2_GetPin();

    ui_config.Led0_Set(( 0 ));
    ui_config.Led1_Set(( 0 ));
    ui_config.Led2_Set(( 0 ));
    ui_config.Led3_Set(( 0 ));
}

_Bool Sw1_GetButtonState(void){
    return UI_SW1_button_pressed;
}

_Bool Sw2_GetButtonState(void){
    return UI_SW2_button_pressed;
}

void Set_LedState(_Bool state, ui_leds led){
    if(led < 0 || led > 3)
        return;

    Gpio_Set table[4];
    table[0] = ui_config.Led0_Set;
    table[1] = ui_config.Led1_Set;
    table[2] = ui_config.Led2_Set;
    table[3] = ui_config.Led3_Set;

    table[led](state);
}
