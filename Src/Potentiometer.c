/************************************************************************
   File:        Program Functions for Read Analog Value "Potentiometer" *
   Author:      Ahmed Baioumy                                 				  *
   Version:     V01                                           				  *
   Date:        27/12/2020                                    				  *
   Updates:     ----                                          				  *
************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "ADC_config.h"
#include "Potentiometer.h"


void Potentiometer_Init(uint8_t Analog_Port , uint8_t Analog_Channel)
{
	/* Enable ADC clock */
	RCC_voidEnableClock (RCC_APB2, RCC_ADC1);
	/* Enable GPIO clock */
	RCC_voidEnableClock (RCC_AHB1, Analog_Port);
	
	/* GPIO Initialize */
	if (Analog_Port == GPIOA)
	{
		GPIO_voidSetPinDirection(Analog_Port , Analog_Channel , GPIO_ANALOG);
		SET_GPIO_SPEED( Analog_Port , Analog_Channel, GPIO_SPEED_FAST );   
		GPIO_SET_PU_PD (Analog_Port , Analog_Channel, GPIO_NO_PU_PD);  
	}
	else if (Analog_Port == GPIOB)
	{
		GPIO_voidSetPinDirection(Analog_Port , Analog_Channel - 8 , GPIO_ANALOG);
		SET_GPIO_SPEED( Analog_Port , Analog_Channel - 8, GPIO_SPEED_FAST );   
		GPIO_SET_PU_PD (Analog_Port , Analog_Channel - 8, GPIO_NO_PU_PD); 
	}
	else {/*return error */}
	
	/* ADC Initialize */
	MADC_voidInit();
}


uint16_t Analog_Read (uint8_t Analog_Channel)
{
	uint16_t value = 0;
		
	/* read analolg signal */
	value = MADC_u16AnalogSingleRead(Analog_Channel); 
		
	return value;
}

uint32_t Get_Angle ( uint8_t Analog_Channel, uint8_t MAX_Angle)
{
	uint32_t Volte = 0;
		
	Volte = Analog_Read ( Analog_Channel) * (MAX_Angle / ((pow(2, ADC_RESOLUTION))-1));
	
	return Volte;
}

