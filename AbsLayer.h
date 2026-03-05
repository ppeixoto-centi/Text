/* 
 * File:   AbsLayer.h
 * Author: ppeixoto
 *
 * Created on March 4, 2026, 1:36 PM
 */

#ifndef ABSLAYER_H
#define	ABSLAYER_H

#ifdef	__cplusplus
extern "C" {
#endif

/* ************************************************************************************ */
/* * Includes                                                                         * */
/* ************************************************************************************ */
    
#include "stdint.h"
    
/* ************************************************************************************ */
/* * Defines                                                                          * */
/* ************************************************************************************ */

#define PERIOD_ELAPSED                  (   1   )
#define NPERIOD_ELAPSED                 (   0   )
    
/* ************************************************************************************ */
/* * Global Variables                                                                 * */
/* ************************************************************************************ */
extern uint8_t period_elapsed;

/*************************************************************************************  */
/* * Public Functions                                                                   */
/* ************************************************************************************ */

void Abs_LayerInit(void);
void Abs_Loop(void);
void ExtISR_Handler(void);
void TIM0_EllapsedTimeCallback(void);
void ADC_CompleteConversionCallback(void);
uint8_t Get_ButtonState(void);  


#ifdef	__cplusplus
}
#endif

#endif	/* ABSLAYER_H */

