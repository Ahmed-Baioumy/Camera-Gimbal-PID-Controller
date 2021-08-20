/************************************************************************
   File:        Interface for Read Analog Value "Potentiometer"         *
   Author:      Ahmed Baioumy                                 				  *
   Version:     V01                                           				  *
   Date:        27/12/2020                                    				  *
   Updates:     ----                                          				  *
************************************************************************/

#ifndef POTENTIOMETER_INTERFACE_H_
#define POTENTIOMETER_INTERFACE_H_

#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"


void Potentiometer_Init(uint8_t Analog_Port , uint8_t Analog_Channel);


/* Read analog value, range from 0 to ADC 2^Resolution 
 * Default form 0 to 4096
 */
uint16_t Analog_Read (uint8_t Analog_Channel);


/* Get real value */
uint32_t Get_Angle (uint8_t Analog_Channel, uint8_t MAX_Angle);


/* Analog_Port OPTIONS: */
#define GPIOA       0
#define GPIOB       1


/* Analog_Chaneel OPTIONS: */
#define ADC_PA0     0
#define ADC_PA1     1
#define ADC_PA2     2
#define ADC_PA3     3
#define ADC_PA4     4
#define ADC_PA5     5
#define ADC_PA6     6
#define ADC_PA7     7
#define ADC_PB0     8
#define ADC_PB1     9




#endif /* POTENTIOMETER_INTERFACE_H_ */

