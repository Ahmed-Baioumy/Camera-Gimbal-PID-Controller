/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
/*Gards           */

#ifndef RCC_config_h
#define RCC_config_h

/*clock type _________________ */
/* options : RCC_HSE_CRYSTAL 
             RCC_HSE_RC
			 RCC_HSI
			 RCC_PLL       */
			 
#define RCC_CLOCK_TYPE   RCC_HSE_CRYSTAL
/* prescalers /*

PPRE2: APB high-speed prescaler (APB2)
Set and cleared by software to control APB high-speed clock division factor.
Caution: The software has to set these bits correctly not to exceed 90 MHz on this domain. 
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after 
PPRE2 write.
0xx: AHB clock not divided
100: AHB clock divided by 2
101: AHB clock divided by 4
110: AHB clock divided by 8
111: AHB clock divided by 16      */

#define PPRE2 0

/*
PPRE1: APB Low speed prescaler (APB1)
Set and cleared by software to control APB low-speed clock division factor.
Caution: The software has to set these bits correctly not to exceed 45 MHz on this domain. 
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after 
PPRE1 write.
0xx: AHB clock not divided
100: AHB clock divided by 2
101: AHB clock divided by 4
110: AHB clock divided by 8
111: AHB clock divided by 16
Bits 9:8 Reserved, must be kept at reset value.    */ 

#define PPRE1 0

/* HPRE: AHB prescaler
Set and cleared by software to control AHB clock division factor.
Caution: The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after 
HPRE write.
Caution: The AHB clock frequency must be at least 25 MHz when the Ethernet is used.
0xxx: system clock not divided
1000: system clock divided by 2
1001: system clock divided by 4
1010: system clock divided by 8
1011: system clock divided by 16
1100: system clock divided by 64
1101: system clock divided by 128
1110: system clock divided by 256
1111: system clock divided by 512
   */
 #define HPRE 0

/*PLL-------------------------- */
/*  
 This register is used to configure the PLL clock outputs according to the formulas:
• f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
• f(PLL general clock output) = f(VCO clock) / PLLP
• f(USB OTG FS, SDIO) = f(VCO clock) / PLLQ
 /
options : 50 ≤ #define PLL_N ≤ 432
Note: Between 50 and 99 multiplication factors are possible for VCO input frequency higher 
than 1 MHz. However care must be taken to fulfill the minimum VCO output frequency 
as specified above. */
#define PLL_N  50
/* 2 ≤ PLLM ≤ 63    */
#define PLL_M      16

/* PLLP = 2, 4, 6, or 8 */
#define PLL_P      2

/* with 2 ≤ PLLQ ≤ 15 */
#define PLL_Q      7
/*
PLLR[2:0]: Main PLL division factor for I2Ss, SAIs, SYSTEM and SPDIF-Rx clocks
Set and cleared by software to control the frequency of the clock. These bits should be 
written only if PLL is disabled.
Clock frequency = VCO frequency / PLLR with 2 ≤ PLLR ≤ 7   */
#define PLLR      7


/*   select only if you have PLL as input clock source  
options : RCC_PLL_HSI
             RCC_PLL_HSE_Crystal
			 RCC_PLL_HSE_RC
			        */
#if RCC_CLOCK_TYPE == RCC_PLL					
#define RCC_PLL_INPUT  RCC_PLL_HSE_Crystal
#endif 

/*----------------------------------------------------------------------------------------------------------------*/





#endif
