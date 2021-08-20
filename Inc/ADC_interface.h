/********************************************************
   File:        ADC Functions and Macros (interace)     *
   Author:      Hamdy Osama Mohamed                     *
   Version:     V01                                     *
   Date:        6/12/2020                               *
   Updates:     ----                                    *
********************************************************/
   
   #ifndef ADC_INTERFACE_H
   #define ADC_INTERFACE_H
   #include "STD_TYPES.h"
   
   void  MADC_voidInit(void); //Used to initialize ADC in system
   
   u16   MADC_u16AnalogSingleRead(u8 Copy_u8Channel); 
   //Used to read single one channel and return conversion value
   /* Copy_u8Channel OPTIONS:*/
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
	 #define ADC_PC0     10
	 #define ADC_PC1     11
	 #define ADC_PC2     12
	 #define ADC_PC3     13
	 #define ADC_PC4     14
	 #define ADC_PC5     15
   
	 
	 
   
   #endif



