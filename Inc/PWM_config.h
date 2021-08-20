/*********************************************************
   File:        interface data of PWM Driver             *
   Author:      Hamdy Osama Mohamed                      *
   Version:     V02                                      *
   Date:        8/2/2021                                 *
   Updates:     Added General Purpose Timers as PWM      *
*********************************************************/


   #ifndef PWM_CONFIG_H
   #define PWM_CONFIG_H
   
   /*This Configuration file uses advanced timers as PWM Generators 
     only and does not allow any other function for the timer...\
	 further features can be added later as needed to operate the 
	 timers in future versions.*/
	 
	 /*Features not present in this version include (Priority to add is descending):
	 DMA
	 (Input)Capture/Compare
	 Slave, Master Mode
	 */
	 
	 /*The Initialization Function automatically sets timers to output PWM Mode*/
	 
	 /*Configurablie Options in this Driver Include:
	 1- Clock Division       			: T_bus/T_clock       (1,2,4) 
	 2- Auto Preload         			: Enable/Disable       (1,0)
	 3- Center-aligned Mode  			: Modes of Counting (Check Macros)
	 4- Couting Direction    			: UP or DOWN        (Check Macros)
	 5- One Pulse Mode       			: Enable/Disable       (1,0)
	 6- Interrupt, DMA Enable			: Enable/Disable       (1,0)
	 7- Output Channels used 			:                     (1,2,3,4)
	 8- PWM Mode             			: Mode 1 or Mode 2      (1,2)
	 9- Output Polarity      			: Active High/Low       (1,0)
	 10- PWM Complementary Channels     : Enable/Disable        (1/0)
	 11- PWM Prescaler                  : Set Value < 65536   (0-65535)
	 */
	 
	 /*1- Clock Division: Set the ratio of timer clock from bus(dead) clock 
	      OPTIONS:
		   1     -> Not divided   (Default)
		   2     -> Divided by 2
		   4     -> Divided by 4
	 */
	 
	 #define PWM_CLK      1
	 
	 /*2- Auto Preload: Set new time period and Duty Cycle only when timer restarts counting
	      OPTIONS:
		  1     -> Enabled    (Default)
		  0     -> Disabled
		  NOTE: be careful when disabling this feature as it might cause logical 
		  errors between software and hardware integration
		*/
	 
	 #define PWM_PRELOAD    1
	 
	 /*3- Center-aligned Mode: Make Counter up counting then down counting repetitively
   	   Disabled/ or enabled with interrupt flags setting in different modes
	   OPTIONS:
	    OFF       -> Disabled  (Default)
		C_MODE1   -> Enabled (Interrupt in cout down only)
		C_MODE2   -> Enabled (Interrupt in count up only)
		C_MODE3   -> Enabled (Interrupt in both up and down count)
		*/
	 
	 #define PWM_CENTER_ALIGN   OFF
	 
	 /*4- Couting Direction: Set timer to count UP or DOWN
	      OPTIONS: 
		  PWM_UP      -> Counter starts from 0 and counts till period value
				      	 then creates overflow interrupt    (Default)
		  PWM_DOWN    -> Counter starts from period value then decrements 
						 till it raches 0 and then create underflow interrupt
	 */
	 
	  #define PWM_COUNT_DIRECTION     PWM_UP
	  
	  /*5- One Pulse Mode: Stop Counter at update event (when interrupt occur)
		OPTIONS:
		 1    -> Enable One Pulse Mode
		 0    -> Disable One Pulse Mode (Default)
	  */
	  
	  #define PWM_ONE_PULSE       0
	  
	  /*6- Interrupt, DMA Enable:  Enable features on Update
	       OPTIONS:
		     1    ->  Enabled
			 0    ->  Disabled   (Default)
	  */
	  
	  #define PWM_INTERRUPT_DMA     0
	  
	  /*7- Output Channels used: The number of output channels controlled
	       by the timer. 
		   OPTIONS:
		    1    -> Default
			2
			3
			4    -> All channels
			*/
   
	   #define PWM_OUTPUT_CHANNELS     4
	   
	   /*8- PWM Mode: Can be in 2 modes, mode1 has default state as high
	        Mode2 has default state as Low. AFTER Duty Cycle, changes the default state
			OPTIONS:
			1 -> Mode 1  (Default)
			2 -> Mode 2 
			*/
			
		#define PWM_MODE                1
		
		/*9- Output Polarity: Set active as High or Low for timer channels
		     OTPIONS:
			  1 -> Active HIGH (Default)
			  0 -> Active LOW  
		*/
		
		#define PWM_POLARITY            1
		
		/*10- PWM Complementary Channels: Activate/Deactivate channels that inverts
		      and mirrors the settings of PWM Channels
			  OPTIONS:
			  1 -> Activate complementary channels
			  0 -> Deactivate complementary channels  (Default)
		*/
		
		#define PWM_COMPLEMENTARY       0
		
		
		/*11- PWM Prescaler: Set the value of timer clock prescaler, the final clock follows the following:
				Bus__Clock/ (Prescaler value + 1)
			  OPTIONS:
			  Any decimal value from 0 to 65535
			  Default Value = 0
		*/
		
		#define PWM_PRESCALER          0
		
		
		
		
   
   #endif