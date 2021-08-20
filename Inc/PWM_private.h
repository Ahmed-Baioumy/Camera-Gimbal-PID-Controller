/*********************************************************
   File:        interface data of PWM Driver             *
   Author:      Hamdy Osama Mohamed                      *
   Version:     V02                                      *
   Date:        8/2/2021                                 *
   Updates:     Added General Purpose Timers as PWM      *
*********************************************************/


   #ifndef PWM_PRIVATE_H
   #define PWM_PRIVATE_H
   
   
   /*Register Definitions*/
   
   #define TIM1_BASE_ADDRESS   0x40010000
   #define TIM8_BASE_ADDRESS   0x40010400
   
   #define TIM2_BASE_ADDRESS   0x40000000
   #define TIM3_BASE_ADDRESS   0x40000400
   #define TIM4_BASE_ADDRESS   0x40000800
   #define TIM5_BASE_ADDRESS   0x40000C00
   
   typedef volatile struct{
		volatile u32 CR1;
		volatile u32 CR2;
		volatile u32 SMCR;
		volatile u32 DIER;
		volatile u32 SR;
		volatile u32 EGR;
		volatile u32 CCMR1;
		volatile u32 CCMR2;
		volatile u32 CCER;
		volatile u32 CNT;
		volatile u32 PSC;
		volatile u32 ARR;
		volatile u32 RCR;
		volatile u32 CCR1;
		volatile u32 CCR2;
		volatile u32 CCR3;
		volatile u32 CCR4;
		volatile u32 BDTR;
		volatile u32 DCR;
		volatile u32 DMAR;
   }Adv_Timer;	   
   
   #define TIM1   ((volatile Adv_Timer*)TIM1_BASE_ADDRESS)
   #define TIM8   ((volatile Adv_Timer*)TIM8_BASE_ADDRESS)
   
   
/*   typedef volatile struct{
		volatile u32 CR1;
		volatile u32 CR2;
		volatile u32 SMCR;
		volatile u32 DIER;
		volatile u32 SR;
		volatile u32 EGR;
		volatile u32 CCMR1;
		volatile u32 CCMR2;
		volatile u32 CCER;
		volatile u32 CNT;
		volatile u32 PSC;
		volatile u32 ARR;
		volatile u32 Reserved_1;
		volatile u32 CCR1;
		volatile u32 CCR2;
		volatile u32 CCR3;
		volatile u32 CCR4;
		volatile u32 Reserved_2;
		volatile u32 DCR;
		volatile u32 DMAR;
   }General_Timer;	   
  */
  
   #define TIM2   ((volatile Adv_Timer*)TIM2_BASE_ADDRESS)
   #define TIM3   ((volatile Adv_Timer*)TIM3_BASE_ADDRESS)
   #define TIM4   ((volatile Adv_Timer*)TIM4_BASE_ADDRESS)
   #define TIM5   ((volatile Adv_Timer*)TIM5_BASE_ADDRESS)
   
   /*Private Macros*/
   
   #define OFF        0
   #define C_MODE1    1
   #define C_MODE2    2
   #define C_MODE3    3
   
   #define PWM_UP     0
   #define PWM_DOWN   1
   
   
   
   
   
   #endif