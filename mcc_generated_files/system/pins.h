/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
© [2026] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define ADC_TRIS                 TRISAbits.TRISA0
#define ADC_LAT                  LATAbits.LATA0
#define ADC_PORT                 PORTAbits.RA0
#define ADC_WPU                  WPUAbits.WPUA0
#define ADC_OD                   ODCONAbits.ODCA0
#define ADC_ANS                  ANSELAbits.ANSELA0
#define ADC_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define ADC_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define ADC_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define ADC_GetValue()           PORTAbits.RA0
#define ADC_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define ADC_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define ADC_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define ADC_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define ADC_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define ADC_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define ADC_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define ADC_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RA3 aliases
#define CS_TRIS                 TRISAbits.TRISA3
#define CS_LAT                  LATAbits.LATA3
#define CS_PORT                 PORTAbits.RA3
#define CS_WPU                  WPUAbits.WPUA3
#define CS_OD                   ODCONAbits.ODCA3
#define CS_ANS                  ANSELAbits.ANSELA3
#define CS_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define CS_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define CS_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define CS_GetValue()           PORTAbits.RA3
#define CS_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define CS_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define CS_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define CS_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define CS_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define CS_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define CS_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define CS_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set RA4 aliases
#define LED_D2_TRIS                 TRISAbits.TRISA4
#define LED_D2_LAT                  LATAbits.LATA4
#define LED_D2_PORT                 PORTAbits.RA4
#define LED_D2_WPU                  WPUAbits.WPUA4
#define LED_D2_OD                   ODCONAbits.ODCA4
#define LED_D2_ANS                  ANSELAbits.ANSELA4
#define LED_D2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define LED_D2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define LED_D2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define LED_D2_GetValue()           PORTAbits.RA4
#define LED_D2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define LED_D2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define LED_D2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define LED_D2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define LED_D2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define LED_D2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define LED_D2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define LED_D2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set RA5 aliases
#define LED_D3_TRIS                 TRISAbits.TRISA5
#define LED_D3_LAT                  LATAbits.LATA5
#define LED_D3_PORT                 PORTAbits.RA5
#define LED_D3_WPU                  WPUAbits.WPUA5
#define LED_D3_OD                   ODCONAbits.ODCA5
#define LED_D3_ANS                  ANSELAbits.ANSELA5
#define LED_D3_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_D3_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_D3_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_D3_GetValue()           PORTAbits.RA5
#define LED_D3_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_D3_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_D3_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_D3_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_D3_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_D3_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_D3_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define LED_D3_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA6 aliases
#define LED_D4_TRIS                 TRISAbits.TRISA6
#define LED_D4_LAT                  LATAbits.LATA6
#define LED_D4_PORT                 PORTAbits.RA6
#define LED_D4_WPU                  WPUAbits.WPUA6
#define LED_D4_OD                   ODCONAbits.ODCA6
#define LED_D4_ANS                  ANSELAbits.ANSELA6
#define LED_D4_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED_D4_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED_D4_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED_D4_GetValue()           PORTAbits.RA6
#define LED_D4_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED_D4_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define LED_D4_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define LED_D4_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define LED_D4_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define LED_D4_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define LED_D4_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define LED_D4_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set RA7 aliases
#define LED_D5_TRIS                 TRISAbits.TRISA7
#define LED_D5_LAT                  LATAbits.LATA7
#define LED_D5_PORT                 PORTAbits.RA7
#define LED_D5_WPU                  WPUAbits.WPUA7
#define LED_D5_OD                   ODCONAbits.ODCA7
#define LED_D5_ANS                  ANSELAbits.ANSELA7
#define LED_D5_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define LED_D5_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define LED_D5_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define LED_D5_GetValue()           PORTAbits.RA7
#define LED_D5_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define LED_D5_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define LED_D5_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define LED_D5_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define LED_D5_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define LED_D5_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define LED_D5_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define LED_D5_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB1 aliases
#define SCK_TRIS                 TRISBbits.TRISB1
#define SCK_LAT                  LATBbits.LATB1
#define SCK_PORT                 PORTBbits.RB1
#define SCK_WPU                  WPUBbits.WPUB1
#define SCK_OD                   ODCONBbits.ODCB1
#define SCK_ANS                  ANSELBbits.ANSELB1
#define SCK_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define SCK_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define SCK_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define SCK_GetValue()           PORTBbits.RB1
#define SCK_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define SCK_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define SDI_TRIS                 TRISBbits.TRISB2
#define SDI_LAT                  LATBbits.LATB2
#define SDI_PORT                 PORTBbits.RB2
#define SDI_WPU                  WPUBbits.WPUB2
#define SDI_OD                   ODCONBbits.ODCB2
#define SDI_ANS                  ANSELBbits.ANSELB2
#define SDI_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define SDI_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define SDI_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define SDI_GetValue()           PORTBbits.RB2
#define SDI_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define SDI_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define SDO_TRIS                 TRISBbits.TRISB3
#define SDO_LAT                  LATBbits.LATB3
#define SDO_PORT                 PORTBbits.RB3
#define SDO_WPU                  WPUBbits.WPUB3
#define SDO_OD                   ODCONBbits.ODCB3
#define SDO_ANS                  ANSELBbits.ANSELB3
#define SDO_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SDO_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SDO_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SDO_GetValue()           PORTBbits.RB3
#define SDO_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SDO_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RB4 aliases
#define SW1_TRIS                 TRISBbits.TRISB4
#define SW1_LAT                  LATBbits.LATB4
#define SW1_PORT                 PORTBbits.RB4
#define SW1_WPU                  WPUBbits.WPUB4
#define SW1_OD                   ODCONBbits.ODCB4
#define SW1_ANS                  ANSELBbits.ANSELB4
#define SW1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW1_GetValue()           PORTBbits.RB4
#define SW1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)
#define RB4_SetInterruptHandler  SW1_SetInterruptHandler

// get/set RC0 aliases
#define RX_TRIS                 TRISCbits.TRISC0
#define RX_LAT                  LATCbits.LATC0
#define RX_PORT                 PORTCbits.RC0
#define RX_WPU                  WPUCbits.WPUC0
#define RX_OD                   ODCONCbits.ODCC0
#define RX_ANS                  ANSELCbits.ANSELC0
#define RX_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RX_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RX_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RX_GetValue()           PORTCbits.RC0
#define RX_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RX_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RX_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RX_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define RX_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define RX_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define TX_TRIS                 TRISCbits.TRISC1
#define TX_LAT                  LATCbits.LATC1
#define TX_PORT                 PORTCbits.RC1
#define TX_WPU                  WPUCbits.WPUC1
#define TX_OD                   ODCONCbits.ODCC1
#define TX_ANS                  ANSELCbits.ANSELC1
#define TX_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define TX_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define TX_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define TX_GetValue()           PORTCbits.RC1
#define TX_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define TX_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define TX_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define TX_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define TX_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define TX_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define TX_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define TX_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set RC5 aliases
#define SW2_TRIS                 TRISCbits.TRISC5
#define SW2_LAT                  LATCbits.LATC5
#define SW2_PORT                 PORTCbits.RC5
#define SW2_WPU                  WPUCbits.WPUC5
#define SW2_OD                   ODCONCbits.ODCC5
#define SW2_ANS                  ANSELCbits.ANSELC5
#define SW2_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW2_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW2_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW2_GetValue()           PORTCbits.RC5
#define SW2_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW2_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the SW1 pin functionality
 * @param none
 * @return none
 */
void SW1_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW1 pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW1 at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW1 pin.
 *        This is a dynamic interrupt handler to be used together with the SW1_SetInterruptHandler() method.
 *        This handler is called every time the SW1 ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW1_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW1 pin. 
 *        This is a predefined interrupt handler to be used together with the SW1_SetInterruptHandler() method.
 *        This handler is called every time the SW1 ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW1_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/