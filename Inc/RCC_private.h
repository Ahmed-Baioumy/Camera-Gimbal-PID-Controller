/************************************/
/* Author : Yomna Attia             */
/* Date : 12/12/2020                */
/* version : 01                     */
/************************************/
#ifndef RCC_private_h
#define RCC_private_h

/*Register Definitions */
#define RCC_CR             *( (volatile u32*)0x40023800)
#define RCC_PLLCFGR        *( (volatile u32*)0x40023804)
#define RCC_CFGR           *( (volatile u32*)0x40023808)
#define RCC_CIR            *( (volatile u32*)0x4002380C)
#define RCC_AHB1RSTR       *( (volatile u32*)0x40023810)
#define RCC_AHB2RSTR       *( (volatile u32*)0x40023814)
#define RCC_AHB3RSTR       *( (volatile u32*)0x40023818)
#define RCC_APB1RSTR       *( (volatile u32*)0x40023820)
#define RCC_APB2RSTR       *( (volatile u32*)0x40023824)
#define RCC_AHB1ENR        *( (volatile u32*)0x40023830)
#define RCC_AHB2ENR        *( (volatile u32*)0x40023834)
#define RCC_AHB3ENR        *( (volatile u32*)0x40023838)
#define RCC_APB1ENR        *( (volatile u32*)0x40023840)
#define RCC_APB2ENR        *( (volatile u32*)0x40023844)
#define RCC_AHB1LPENR      *( (volatile u32*)0x40023850)
#define RCC_AHB2LPENR      *( (volatile u32*)0x40023854)
#define RCC_AHB3LPENR      *( (volatile u32*)0x40023858)
#define RCC_APB1LPENR      *( (volatile u32*)0x40023860)
#define RCC_APB2LPENR      *( (volatile u32*)0x40023864)
#define RCC_BDCR           *( (volatile u32*)0x40023870)
#define RCC_CSR            *( (volatile u32*)0x40023874)
#define RCC_SSCGR          *( (volatile u32*)0x40023880)
#define RCC_PLLI2SCFGR     *( (volatile u32*)0x40023884)
#define RCC_PLLSAICFGR     *( (volatile u32*)0x40023888)
#define RCC_DCKCFGR        *( (volatile u32*)0x4002388C)
#define RCC_CKGATENR       *( (volatile u32*)0x40023890)
#define RCC_DCKCFGR2       *( (volatile u32*)0x40023894)


/* CLOCK TYPES*/ 
#define RCC_HSE_CRYSTAL     0
#define RCC_HSE_RC          1
#define RCC_HSI             2
#define RCC_PLL             3


/* PLL options*/
#define RCC_PLL_HSI            0
#define RCC_PLL_HSE_Crystal    1
#define RCC_PLL_HSE_RC         2
			        
#endif