/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
				 
void RCC_voidInitSysClock (void)
{
#if     RCC_CLOCK_TYPE  ==  RCC_HSE_CRYSTAL 
        RCC_CR |= 0x00010000; /*Enable HSE with no bypass */
		RCC_CFGR = 0x00000001;
		RCC_CFGR |=   ((PPRE2)<<13);
		RCC_CFGR |=   ((PPRE1)<<10);
		RCC_CFGR |=     ((HPRE)<<4);
	RCC_CR &= ~(1U);     /*Close HSI*/
#elif   RCC_CLOCK_TYPE  ==  RCC_HSE_RC
        RCC_CR |= 0x00040000; /*Enable HSE bypass */
		 RCC_CR |= 0x00010000; /*Enable HSE*/
		RCC_CFGR = 0x00000001;
		RCC_CFGR |=   ((PPRE2)<<13);
		RCC_CFGR |=   ((PPRE1)<<10);
		RCC_CFGR |=     ((HPRE)<<4);
	RCC_CR &= ~(1U);     /*Close HSI*/
#elif   RCC_CLOCK_TYPE  ==  RCC_HSI
        RCC_CR = 0x00000081;  /*Enable HSI + Triming =0 */
		RCC_CFGR = 0x00000000;
		RCC_CFGR |=   ((PPRE2)<<13);
		RCC_CFGR |=   ((PPRE1)<<10);
		RCC_CFGR |=     ((HPRE)<<4);
#elif   RCC_CLOCK_TYPE  ==  RCC_PLL
		RCC_PLLCFGR|= ((PLL_N)<<6);
		RCC_PLLCFGR|= ((PLL_M)<<0);
		RCC_PLLCFGR|= ((PLL_P)<<16);
		RCC_PLLCFGR|= ((PLL_Q)<<24);
		RCC_PLLCFGR|= ((PLLR)<<28);
		RCC_CFGR = 0x00000010;
		RCC_CFGR |=   ((PPRE2)<<13);
		RCC_CFGR |=   ((PPRE1)<<10);
		RCC_CFGR |=     ((HPRE)<<4);

       #if RCC_PLL_INPUT ==  RCC_PLL_HSI
	            RCC_CR   =    0x01000081; //Enable HSI , No Bias in trim, and Enable PLL
				
       #elif RCC_PLL_INPUT ==  RCC_PLL_HSE_Crystal
	     
				RCC_CR    =    0x01010000;      //Enable HSE, No Bypass, and Enable PLL
			
	   #elif RCC_PLL_INPUT ==  RCC_PLL_HSE_RC
			
				RCC_CR   =    0x01050000;      //Enable HSE , with Bypass, and Enable PLL
		   
			
	   #else   
	     #error ("You chosed Wrong RCC_PLL_INPUT ")
	  #endif
#else   
	#error ("You chosed Wrong CLOCK TYPE ")
#endif
}

void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if ( Copy_u8PerId<= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB1 :      SET_BIT(RCC_AHB1ENR,Copy_u8PerId);  break;
			case RCC_AHB2 :      SET_BIT(RCC_AHB2ENR,Copy_u8PerId);  break;
			case RCC_AHB3 :      SET_BIT(RCC_AHB3ENR,Copy_u8PerId);  break;
			case RCC_APB1:       SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2:       SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
			case RCC_AHB1LP:     SET_BIT(RCC_AHB1LPENR,Copy_u8PerId);  break;
			case RCC_AHB2LP:     SET_BIT(RCC_AHB2LPENR,Copy_u8PerId);  break;
			case RCC_AHB3LP:     SET_BIT(RCC_AHB3LPENR,Copy_u8PerId);  break;
			case RCC_APB1LP:     SET_BIT(RCC_APB1LPENR,Copy_u8PerId);  break;
			case RCC_APB2LP:     SET_BIT(RCC_APB2LPENR,Copy_u8PerId);  break;
			default    :/* Return Error */  break; 
		}
	}
	else 
	{
		/* Return Error */
	}
}
	
void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PerId)
{
	if ( Copy_u8PerId<= 31)
	{
		switch(Copy_u8BusId)
		{
			case RCC_AHB1 :    CLR_BIT(RCC_AHB1ENR,Copy_u8PerId);  break;
			case RCC_AHB2 :    CLR_BIT(RCC_AHB2ENR,Copy_u8PerId);  break;
			case RCC_AHB3 :    CLR_BIT(RCC_AHB3ENR,Copy_u8PerId);  break;
			case RCC_APB1:     CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
			case RCC_APB2:     CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
			case RCC_AHB1LP:   CLR_BIT(RCC_AHB1LPENR,Copy_u8PerId);  break;
			case RCC_AHB2LP:   CLR_BIT(RCC_AHB2LPENR,Copy_u8PerId);  break;
			case RCC_AHB3LP:   CLR_BIT(RCC_AHB3LPENR,Copy_u8PerId);  break;
			case RCC_APB1LP:   CLR_BIT(RCC_APB1LPENR,Copy_u8PerId);  break;
			case RCC_APB2LP:   CLR_BIT(RCC_APB2LPENR,Copy_u8PerId);  break;
			default    :/* Return Error */  break; 
		}
	}
	else 
	{
		/* Return Error */
	}
}
