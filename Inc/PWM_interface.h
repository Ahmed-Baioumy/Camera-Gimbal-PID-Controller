/*********************************************************
   File:        interface data of PWM Driver             *
   Author:      Hamdy Osama Mohamed                      *
   Version:     V02                                      *
   Date:        8/2/2021                                 *
   Updates:     Added General Purpose Timers as PWM      *
*********************************************************/


   #ifndef PWM_INTERFACE_H
   #define PWM_INTERFACE_H
   
   void PWM_Init(u8 Timer); 								//Used to initialize configuration properties for the given Timer
   void PWM_Pin (u8 Pin);                                   //Used to set selected pin as PWM pin (alternative function
   void PWM_PinWrite(u8 Pin, u32 DutyCycle, u32 Period);	//Used to set Duty Cycle (Check Range Below) and Period of PWM Signal
   void PWM_PinStop(u8 Pin);								//Used to stop the PWM signal from being created on selected pin
   
   /*Note about Period of PWM Signal:
	 This value is sensitive as it is greatly dependent on the responsiveness of the system being driven, it is greatly advisable to stick 
	 to given value unless you wish to optimize your system and test better values.
   */
   
   //Macros used in the PWM Function Arguments:
   
   /*Values for "Timer"*/
   //Advanced Timers
   #define TIMER1      1
   #define TIMER8      8
	 #define TIMER2      2
   
   /*Pins available for each timer*/
   //Timer 1
   #define PWM_PA8    4    //(Timer 1 Channel 1)
   #define PWM_PA9    5    //(Timer 1 Channel 2)
   #define PWM_PA10   10   //(Timer 1 Channel 3)
   #define PWM_PA11   11   //(Timer 1 Channel 4)
   //Timer 8
   #define PWM_PC6    6    //(Timer 8 Channel 1)
   #define PWM_PC7    7    //(Timer 8 Channel 2)
   #define PWM_PC8    8	   //(Timer 8 Channel 3)
   #define PWM_PC9    9    //(Timer 8 Channel 4)
   //Timer 2
   #define PWM_PA15   15   //(Timer 2 Channel 1)
   #define PWM_PB3    33   //(Timer 2 Channel 2)
   #define PWM_PB10   101 //(Timer 2 Channel 3)
   #define PWM_PA3    3    //(Timer 2 Channel 4)
   
   
   /*Duty Cycle Possible Value*/
   // From 0 to 65535   (0 is like GPIO LOW) (65535 is like GPIO HIGH)
   
   /*Period Possible Value*/
   // From 0 to 65535 -> (Timing is relative to bus clock and configured 
   // prescaler. 
   
   /*These values are temporary until driver gets refined in future versions
     to directly get duty cycle percentage and period in milliseconds
   */
   
   #endif