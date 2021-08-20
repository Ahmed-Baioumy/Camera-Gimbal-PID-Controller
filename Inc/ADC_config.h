/********************************************************
   File:        Configuration Properties of ADC Driver  *
   Author:      Hamdy Osama Mohamed                     *
   Version:     V01                                     *
   Date:        6/12/2020                               *
   Updates:     ----                                    *
********************************************************/
   
   #ifndef ADC_CONFIG_H
   #define ADC_CONFIG_H
   
   /*This Configuration File Settings apply only for ADC1
   and generalizes settings for all channels available.
   Specific functions will be added in later updates to 
   give the programmer more control on specific channels
   and ADC2, ADC3 Operation */
   
   //Continuous Mode is OFF by default.
   
   
   /*Configuration Options:
       1- ADC Clock Prescaler                (2/4/6/8)
       2- Overrun Interrupt Enable           (0/1)
	   3- Resolution of ADC                  (12/10/8/6)
	   4- Analog Watch Dog Enable            (0/1)
	   5- Sampling Time                      (Check OPTIONS)
	   6- Discontinuous count mode Enable    (0/1)
	   7- Discontinuous Mode Channels        (1/2/3/4/5/6/7/8)
	   8- Automatic J group conversion       (0/1)
	   9- Scan Mode Enable                   (0/1)
	  10- Interrupt Enable                   (0/1)
	  11- External Trigger Settings          (Check Macros)
	  12- Align ADC Data                     (R/L)
	  13- End of Conversion Selection        (0/1)
	  14- DMA Mode Settings                  (Check Macros)
   */
   
   //1- ADC Clock Prescaler
		/* The value chosen is the portion of the APB2 Bus clock that 
           will be used to run the ADC. Default value is (2)   */
	   
	   #define ADC_PRESCALER              2
	   
    //2- Overrun Interrupt Enable
		/* (1)for enabling interrupt, (0) for disabling feature. 
		   Default is (0)                                       */
		   
		#define ADC_OVERRUN_INTERRUPT      0
		
	//3- Resolution of ADC
		/* choose ADC resolution from 12, 10, 8, or 6 bit data
		   note that lower bit data is faster but with lost accuracy
		   Default value is 12 bit                              */
		
		#define ADC_RESOLUTION             12
	
	//4- Analog Watchdog Enable
		/* (1) to enable regular and injected watchdog, (0) to disable 
		    feature. Default is (0).Note that it enables interrupt
            too. Note that it enables watchdog on all channels	*/
		
		#define ADC_WATCHDOG_ENABLE         0
	
	//5- Sampling Time
		/* Set the number of cycles needed to charge capacitors to
		convert analog data correctly. Higher values lead to more 
		accurate results but take more time to excecute. 
		Default Value = 3 cycles.    
		OPTIONS:  3, 15, 28, 56, 84, 112, 144, 480               */
		
		#define ADC_SAMPLING_CYCLES          3
		
	//6,7- Discontinuous Mode Settings
		/* Choose the Number of regular channels to convert after 
		   recieving an external interrupt. value from 1 to 8
		   Default = 1                                           */
		
		#define DISC_CHANNELS                 1
		
		/* (1) to enable Discontinuous mode in regular and injected
		    channels, (0) to disable feature. Default is (0).     */
		
		#define DISC_MODE                     0 
		
	//8- Automatic Injected Group Conversion
		/* Used to immediately start conversion on Injected channels 
		   after each regular channel end of conversion.(1)/Enable
		   (0)/Disable -> Default                                  */
		   
		#define AUTO_J_CONVERSION             0
		
	//9- Scan Mode Enable
		/* Scans channels written in sequence register in order, generates
			interrupts after each conversion for regular channels, and 
			after all four injected channel conversions. 
			(1)/Enable -> Default                  (0)/ Disable      */
			
		#define SCAN_MODE                      1
		
		/* Choose the number of scanned channels. from 1 to 16.
		   Default is 1 channel.                                     */
		   
		#define SCANNED_CHANNELS                1
		
	//10- Interrupts of ADC Peripheral Enabling
		/* (1)/Enable regular and injected interrupts  
		   (0)/Disable Feature  -> Default                                     */
		   
		#define ADC_INTERRUPTS                   0
		
	//11- External Trigger Settings
		/* Choose the state of external trigger for regular and
		   injected channels                                         */
		   /*OPTIONS:
		              RISING_EDGE         
					  FALLING_EDGE
					  RISING_FALLING_EDGE
					  OFF     ->Default  -> Disable External Trigger */
					  
		#define EXTERNAL_TRIGGER               OFF
		
		/* Note: Selecting the external trigger event is done in 
		software functions when needed in later updates.              */
				 
				 
	//12- Align ADC DATA
		/* Used to coose Right or Left Allignment. 
		     OPTIONS:
		              RIGHT         ->Default
					  LEFT       					                 */
		#define ADC_DATA_ALIGN                    RIGHT
		
	//13- End of Conversion Selection
		/* (0) set EOC Bit after each sequence of regular conversions
		   (1) set EOC Bit after each regular conversion -> Default  */
		   
		#define EOC_SELECTION                        1
		
	//14- DMA Enable
		/* (0) for Disable -> Default
		   (1) for Enable, will be added in future updates to make fast 
		       memory operations without loadng CPU registers*/
		
		#define DMA_MODE                              0
#endif

