/*********************************************************
   File:        interface data of PWM Driver             *
   Author:      Hamdy Osama Mohamed                      *
   Version:     V02                                      *
   Date:        8/2/2021                                 *
   Updates:     Added General Purpose Timers as PWM      *
*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
				 
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
				 
#include "GPIO_interface.h"


void PWM_Init(u8 Timer){
	//Check Input Timer
	if(Timer ==TIMER1){
		//Set Configuration Properties
		//Set PWM CLOCK
		TIM1 -> CR1 = 0;   //Reset register
		switch (PWM_CLK){    //Check config parameter
			case 1  : TIM1 -> CR1 |= (0<<8);break;
			case 2  : TIM1 -> CR1 |= (1<<8);break;
			case 4  : TIM1 -> CR1 |= (2<<8);break;
			default : break;
		}
		/*****************************/
		if (PWM_PRELOAD<2){ 				  //Check preload config
			TIM1 -> CR1 |= (PWM_PRELOAD<<7);   //set preload config
		}
		else{
			//ERROR
		}
		/******************************/
		switch (PWM_CENTER_ALIGN){			//Check Center Align Mode config
			case OFF     : TIM1 -> CR1 |= (0<<5);break;
			case C_MODE1 : TIM1 -> CR1 |= (1<<5);break;
			case C_MODE2 : TIM1 -> CR1 |= (2<<5);break;
			case C_MODE3 : TIM1 -> CR1 |= (3<<5);break;
			default      : break;
		}
		/******************************/
		if (PWM_COUNT_DIRECTION<2){ 		          //Check direction config
			TIM1 -> CR1 |= (PWM_COUNT_DIRECTION<<4);   //set direction config
		}
		else{
			//ERROR
		}
		/******************************/
		if (PWM_ONE_PULSE<2){ 		            //Check one pulse mode config
			TIM1 -> CR1 |= (PWM_ONE_PULSE<<3);   //set one pulse mode config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM1 -> CR2 = 0;   //Reset register
		/******************************/
		TIM1 -> SMCR = 0;  //Reset register
		/******************************/
		TIM1 -> DIER = 0;  //Reset register
		if (PWM_INTERRUPT_DMA<2){ 		            //Check DMA/INTERRUPT config
			TIM1 -> DIER |= (PWM_INTERRUPT_DMA<<8);   //set DMA config
			TIM1 -> DIER |= (PWM_INTERRUPT_DMA<<0);   //set INTERRUPT config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM1 -> CCMR1 = 0;  //Reset CH1/CH2 register
		TIM1 -> CCMR2 = 0;  //Reset CH3/CH4 register
		switch (PWM_OUTPUT_CHANNELS){
			case 1: {
				if(PWM_PRELOAD == 1){
				TIM1 -> CCMR1 |= (1<<3); //Set Preload on duty cycle on CH1
				}
				if (PWM_MODE == 2){
					TIM1 -> CCMR1 |= (7<<4); //Set CH1 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM1 -> CCMR1 |= (6<<4); //Set CH1 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 2: {
				if(PWM_PRELOAD == 1){
				TIM1 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM1 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				}
				if (PWM_MODE == 2){
					TIM1 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM1 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM1 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM1 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 3: {
				if(PWM_PRELOAD == 1){
				TIM1 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM1 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM1 -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				}
				if (PWM_MODE == 2){
					TIM1 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM1 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM1 -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM1 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM1 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM1 -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 4: {
				if(PWM_PRELOAD == 1){
				TIM1 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM1 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM1 -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				TIM1 -> CCMR2 |= (1<<11);     //Set Preload on duty cycle on CH4
				}
				if (PWM_MODE == 2){
					TIM1 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM1 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM1 -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
					TIM1 -> CCMR2 |= (7<<12); //Set CH4 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM1 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM1 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM1 -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
					TIM1 -> CCMR2 |= (6<<12); //Set CH4 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			default: break;
		}
		/******************************/
		TIM1 -> CCER = 0; //Reset Channel Enable Register
		if (PWM_POLARITY<1){
			//Set Polarity as configured for all channels
			TIM1 -> CCER |=((1<<13)|(1<<11)|(1<<9)|(1<<7)|(1<<5)|(1<<3)|(1<<1));
		}
		//Enabling Channels and Complementary is done as needed in Write Function
		/******************************/
		if (PWM_PRESCALER<65536){   		//Check Prescaler Config
			TIM1 -> PSC = PWM_PRESCALER; 	//Set Prescaler configured
		}
		/******************************/
		//Reset Other Driver Registers
		TIM1 -> CNT  = 0;
		TIM1 -> ARR  = 0;
		TIM1 -> RCR  = 0;
		TIM1 -> CCR1 = 0;
		TIM1 -> CCR2 = 0;
		TIM1 -> CCR3 = 0;
		TIM1 -> CCR4 = 0;
		TIM1 -> DCR  = 0;
		TIM1 -> DMAR = 0;
		TIM1 -> BDTR = 0;
		//Enable main output for all channels
		TIM1 -> BDTR |= (1<<15);
	}
	else if(Timer ==TIMER8){
		//Set Configuration Properties
		//Set PWM CLOCK
		TIM8 -> CR1 = 0;   //Reset register
		switch (PWM_CLK){    //Check config parameter
			case 1  : TIM8 -> CR1 |= (0<<8);break;
			case 2  : TIM8 -> CR1 |= (1<<8);break;
			case 4  : TIM8 -> CR1 |= (2<<8);break;
			default : break;
		}
		/*****************************/
		if (PWM_PRELOAD<2){ 				  //Check preload config
			TIM8 -> CR1 |= (PWM_PRELOAD<<7);   //set preload config
		}
		else{
			//ERROR
		}
		/******************************/
		switch (PWM_CENTER_ALIGN){			//Check Center Align Mode config
			case OFF     : TIM8 -> CR1 |= (0<<5);break;
			case C_MODE1 : TIM8 -> CR1 |= (1<<5);break;
			case C_MODE2 : TIM8 -> CR1 |= (2<<5);break;
			case C_MODE3 : TIM8 -> CR1 |= (3<<5);break;
			default      : break;
		}
		/******************************/
		if (PWM_COUNT_DIRECTION<2){ 		          //Check direction config
			TIM8 -> CR1 |= (PWM_COUNT_DIRECTION<<4);   //set direction config
		}
		else{
			//ERROR
		}
		/******************************/
		if (PWM_ONE_PULSE<2){ 		            //Check one pulse mode config
			TIM8 -> CR1 |= (PWM_ONE_PULSE<<3);   //set one pulse mode config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM8 -> CR2 = 0;   //Reset register
		/******************************/
		TIM8 -> SMCR = 0;  //Reset register
		/******************************/
		TIM8 -> DIER = 0;  //Reset register
		if (PWM_INTERRUPT_DMA<2){ 		            //Check DMA/INTERRUPT config
			TIM8 -> DIER |= (PWM_INTERRUPT_DMA<<8);   //set DMA config
			TIM8 -> DIER |= (PWM_INTERRUPT_DMA<<0);   //set INTERRUPT config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM8 -> CCMR1 = 0;  //Reset CH1/CH2 register
		TIM8 -> CCMR2 = 0;  //Reset CH3/CH4 register
		switch (PWM_OUTPUT_CHANNELS){
			case 1: {
				if(PWM_PRELOAD == 1){
				TIM8 -> CCMR1 |= (1<<3); //Set Preload on duty cycle on CH1
				}
				if (PWM_MODE == 2){
					TIM8 -> CCMR1 |= (7<<4); //Set CH1 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM8 -> CCMR1 |= (6<<4); //Set CH1 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 2: {
				if(PWM_PRELOAD == 1){
				TIM8 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM8 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				}
				if (PWM_MODE == 2){
					TIM8 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM8 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM8 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM8 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 3: {
				if(PWM_PRELOAD == 1){
				TIM8 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM8 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM8 -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				}
				if (PWM_MODE == 2){
					TIM8 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM8 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM8 -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM8 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM8 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM8 -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 4: {
				if(PWM_PRELOAD == 1){
				TIM8 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM8 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM8 -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				TIM8 -> CCMR2 |= (1<<11);     //Set Preload on duty cycle on CH4
				}
				if (PWM_MODE == 2){
					TIM8 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM8 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM8 -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
					TIM8 -> CCMR2 |= (7<<12); //Set CH4 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM8 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM8 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM8 -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
					TIM8 -> CCMR2 |= (6<<12); //Set CH4 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			default: break;
		}
		/******************************/
		TIM8 -> CCER = 0; //Reset Channel Enable Register
		if (PWM_POLARITY<1){
			//Set Polarity as configured for all channels
			TIM8 -> CCER |=((1<<13)|(1<<11)|(1<<9)|(1<<7)|(1<<5)|(1<<3)|(1<<1));
		}
		//Enabling Channels and Complementary is done as needed in Write Function
		/******************************/
		if (PWM_PRESCALER<65536){   		//Check Prescaler Config
			TIM8 -> PSC = PWM_PRESCALER; 	//Set Prescaler configured
		}
		/******************************/
		//Reset Other Driver Registers
		TIM8 -> CNT  = 0;
		TIM8 -> ARR  = 0;
		TIM8 -> RCR  = 0;
		TIM8 -> CCR1 = 0;
		TIM8 -> CCR2 = 0;
		TIM8 -> CCR3 = 0;
		TIM8 -> CCR4 = 0;
		TIM8 -> DCR  = 0;
		TIM8 -> DMAR = 0;
		TIM8 -> BDTR = 0;
		//Enable main output for all channels
		TIM8 -> BDTR |= (1<<15);
	}
	else if(Timer ==TIMER2){
		//Set Configuration Properties
		//Set PWM CLOCK
		TIM2 -> CR1 = 0;   //Reset register
		switch (PWM_CLK){    //Check config parameter
			case 1  : TIM2 -> CR1 |= (0<<8);break;
			case 2  : TIM2 -> CR1 |= (1<<8);break;
			case 4  : TIM2 -> CR1 |= (2<<8);break;
			default : break;
		}
		/*****************************/
		if (PWM_PRELOAD<2){ 				  //Check preload config
			TIM2 -> CR1 |= (PWM_PRELOAD<<7);   //set preload config
		}
		else{
			//ERROR
		}
		/******************************/
		switch (PWM_CENTER_ALIGN){			//Check Center Align Mode config
			case OFF     : TIM2 -> CR1 |= (0<<5);break;
			case C_MODE1 : TIM2 -> CR1 |= (1<<5);break;
			case C_MODE2 : TIM2 -> CR1 |= (2<<5);break;
			case C_MODE3 : TIM2 -> CR1 |= (3<<5);break;
			default      : break;
		}
		/******************************/
		if (PWM_COUNT_DIRECTION<2){ 		          //Check direction config
			TIM2 -> CR1 |= (PWM_COUNT_DIRECTION<<4);   //set direction config
		}
		else{
			//ERROR
		}
		/******************************/
		if (PWM_ONE_PULSE<2){ 		            //Check one pulse mode config
			TIM2 -> CR1 |= (PWM_ONE_PULSE<<3);   //set one pulse mode config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM2 -> CR2 = 0;   //Reset register
		/******************************/
		TIM2 -> SMCR = 0;  //Reset register
		/******************************/
		TIM2 -> DIER = 0;  //Reset register
		if (PWM_INTERRUPT_DMA<2){ 		            //Check DMA/INTERRUPT config
			TIM2 -> DIER |= (PWM_INTERRUPT_DMA<<8);   //set DMA config
			TIM2 -> DIER |= (PWM_INTERRUPT_DMA<<0);   //set INTERRUPT config
		}
		else{
			//ERROR
		}
		/******************************/
		TIM2 -> CCMR1 = 0;  //Reset CH1/CH2 register
		TIM2 -> CCMR2 = 0;  //Reset CH3/CH4 register
		switch (PWM_OUTPUT_CHANNELS){
			case 1: {
				if(PWM_PRELOAD == 1){
				TIM2 -> CCMR1 |= (1<<3); //Set Preload on duty cycle on CH1
				}
				if (PWM_MODE == 2){
					TIM2 -> CCMR1 |= (7<<4); //Set CH1 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM2 -> CCMR1 |= (6<<4); //Set CH1 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 2: {
				if(PWM_PRELOAD == 1){
				TIM2 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM2 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				}
				if (PWM_MODE == 2){
					TIM2 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM2 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM2 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM2 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 3: {
				if(PWM_PRELOAD == 1){
				TIM2 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM2 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM2 -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				}
				if (PWM_MODE == 2){
					TIM2 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM2 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM2 -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM2 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM2 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM2 -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			case 4: {
				if(PWM_PRELOAD == 1){
				TIM2 -> CCMR1 |= (1<<3);      //Set Preload on duty cycle on CH1
				TIM2 -> CCMR1 |= (1<<11);     //Set Preload on duty cycle on CH2
				TIM2 -> CCMR2 |= (1<<3);      //Set Preload on duty cycle on CH3
				TIM2 -> CCMR2 |= (1<<11);     //Set Preload on duty cycle on CH4
				}
				if (PWM_MODE == 2){
					TIM2 -> CCMR1 |= (7<<4);  //Set CH1 on PWM Mode 2
					TIM2 -> CCMR1 |= (7<<12); //Set CH2 on PWM Mode 2
					TIM2 -> CCMR2 |= (7<<4);  //Set CH3 on PWM Mode 2
					TIM2 -> CCMR2 |= (7<<12); //Set CH4 on PWM Mode 2
				}
				else if (PWM_MODE == 1){
					TIM2 -> CCMR1 |= (6<<4);  //Set CH1 on PWM Mode 1
					TIM2 -> CCMR1 |= (6<<12); //Set CH2 on PWM Mode 1
					TIM2 -> CCMR2 |= (6<<4);  //Set CH3 on PWM Mode 1
					TIM2 -> CCMR2 |= (6<<12); //Set CH4 on PWM Mode 1
				}
				else{
					//Error
				}
				break;
			}
			default: break;
		}
		/******************************/
		TIM2 -> CCER = 0; //Reset Channel Enable Register
		if (PWM_POLARITY<1){
			//Set Polarity as configured for all channels
			TIM2 -> CCER |=((1<<13)|(1<<11)|(1<<9)|(1<<7)|(1<<5)|(1<<3)|(1<<1));
		}
		//Enabling Channels and Complementary is done as needed in Write Function
		/******************************/
		if (PWM_PRESCALER<65536){   		//Check Prescaler Config
			TIM2 -> PSC = PWM_PRESCALER; 	//Set Prescaler configured
		}
		/******************************/
		//Reset Other Driver Registers
		TIM2 -> CNT  = 0;
		TIM2 -> ARR  = 0;
		TIM2 -> RCR  = 0;
		TIM2 -> CCR1 = 0;
		TIM2 -> CCR2 = 0;
		TIM2 -> CCR3 = 0;
		TIM2 -> CCR4 = 0;
		TIM2 -> DCR  = 0;
		TIM2 -> DMAR = 0;
		TIM2 -> BDTR = 0;
		//Enable main output for all channels
		TIM2 -> BDTR |= (1<<15);
	}
	else{
		//ERROR
	}
}




void PWM_PinWrite(u8 Pin, u32 DutyCycle, u32 Period){
	switch (Pin){ //Check Pin used as PWM if supported
		case PWM_PA8 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA9 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA10 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM1 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA11 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM1 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM1 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM1 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM1 -> CR1  |=(1<<0);     //Enable timer 1
			}
			else{
				TIM1 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		case PWM_PC6 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM8 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PC7 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM8 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PC8 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM8 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PC9 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM8 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM8 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM8 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM8 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM8 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		case PWM_PA15 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR1 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<0);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM2 -> CCER |= (1<<2);  //Enable complementary output for CH1 (CH1N)
				}
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB3 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR2 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<4);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM2 -> CCER |= (1<<6);  //Enable complementary output for CH1 (CH1N)
				}
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PB10 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR3 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<8);		 //Enable Timer output at CH1
				if (PWM_COMPLEMENTARY){      //Check complementary enable
					TIM2 -> CCER |= (1<<10);  //Enable complementary output for CH1 (CH1N)
				}
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH1 and CH1N
			}
			break;
		}
		case PWM_PA3 : {
			if ((DutyCycle<65536)&&(Period<65536)){   //Check Given parameters validity
				TIM2 -> CCR4 = DutyCycle;    //Set Duty cycle in compare register
				TIM2 -> ARR  = Period;		 //Set Period of timer in ARR register
				TIM2 -> CCER |=(1<<12);		 //Enable Timer output at CH1
				TIM2 -> CR1  |=(1<<0);     //Enable timer 8
			}
			else{
				TIM2 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH1 
			}
			break;
		}
		default: break;
	}
	
}




void PWM_PinStop(u8 Pin){
	switch (Pin){ //Check Pin used as PWM if supported
		case PWM_PA8 : {
			TIM1 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PA9 : {
			TIM1 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PA10 : {
			TIM1 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PA11 : {
			TIM1 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4
			break;
		}
		case PWM_PC6 : {
			TIM8 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PC7 : {
			TIM8 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PC8 : {
			TIM8 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PC9 : {
			TIM8 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4 
			break;
		}
		case PWM_PA15 : {
			TIM2 -> CCER &= ~ (5<<0);    //Clear enable output bits for CH1 and CH1N
			break;
		}
		case PWM_PB3 : {
			TIM2 -> CCER &= ~ (5<<4);    //Clear enable output bits for CH2 and CH2N
			break;
		}
		case PWM_PB10 : {
			TIM2 -> CCER &= ~ (5<<8);    //Clear enable output bits for CH3 and CH3N
			break;
		}
		case PWM_PA3 : {
			TIM2 -> CCER &= ~ (1<<12);    //Clear enable output bits for CH4 
			break;
		}
		default: break;
}
}



void PWM_Pin (u8 Pin){
	switch (Pin){ //Check Pin used as PWM if supported
		case PWM_PA8 : {
			GPIO_Set_AF(GPIOA , PIN8 , 1 );    //Set pin 8 as alternative function for timer 1
			break;
		}
		case PWM_PA9 : {
			GPIO_Set_AF(GPIOA , PIN9 , 1 );    //Set pin 9 as alternative function for timer 1
			break;
		}
		case PWM_PA10 : {
			GPIO_Set_AF(GPIOA , PIN10 , 1 );    //Set pin 10 as alternative function for timer 1
			break;
		}
		case PWM_PA11 : {
			GPIO_Set_AF(GPIOA , PIN11 , 1 );    //Set pin 11 as alternative function for timer 1
			break;
		}
		case PWM_PC6 : {
			GPIO_Set_AF(GPIOC , PIN6 , 3 );    //Set pin 6 as alternative function for timer 8
			break;
		}
		case PWM_PC7 : {
			GPIO_Set_AF(GPIOC , PIN7 , 3 );    //Set pin 7 as alternative function for timer 8
			break;
		}
		case PWM_PC8 : {
			GPIO_Set_AF(GPIOC , PIN8 , 3 );    //Set pin 8 as alternative function for timer 8
			break;
		}
		case PWM_PC9 : {
			GPIO_Set_AF(GPIOC , PIN9 , 3 );    //Set pin 9 as alternative function for timer 8
			break;
		}
		case PWM_PA15 : {
			GPIO_Set_AF(GPIOA , PIN15 , 1 );    //Set pin 6 as alternative function for timer 8
			break;
		}
		case PWM_PB3 : {
			GPIO_Set_AF(GPIOB , PIN3 , 1 );    //Set pin 7 as alternative function for timer 8
			break;
		}
		case PWM_PB10 : {
			GPIO_Set_AF(GPIOB , PIN10 , 1 );    //Set pin 8 as alternative function for timer 8
			break;
		}
		case PWM_PA3 : {
			GPIO_Set_AF(GPIOA , PIN3 , 1 );    //Set pin 9 as alternative function for timer 8
			break;
		}
		default: break;
}
}






