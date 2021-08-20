/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 11 December 2020                                 */
/* Version : V02.5                                            */
/*************************************************************/
#ifndef  GPIO_PRIVATE_H
#define  GPIO_PRIVATE_H

#define  GPIOA_BASE_ADDRESS  0x40020000
#define  GPIOB_BASE_ADDRESS  0x40020400
#define  GPIOC_BASE_ADDRESS  0x40020800
#define  GPIOD_BASE_ADDRESS  0x40020C00
#define  GPIOE_BASE_ADDRESS  0x40021000
#define  GPIOF_BASE_ADDRESS  0x40021400
#define  GPIOG_BASE_ADDRESS  0x40021800
#define  GPIOH_BASE_ADDRESS  0x40021C00



  
                    /* REGISTERS ADDRESSES FOR PORTA  */

#define   GPIOA_MODER                                *((u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define   GPIOA_OTYPER                               *((u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define   GPIOA_OSPEEDER                             *((u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define   GPIOA_PUPDR                                *((u32 *)(GPIOA_BASE_ADDRESS + 0x0c))
#define   GPIOA_IDR                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define   GPIOA_ODR                                  *((u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define   GPIOA_BSRR                                 *((u32 *)(GPIOA_BASE_ADDRESS + 0x18))
#define   GPIOA_LCKR                                 *((u32 *)(GPIOA_BASE_ADDRESS + 0x1c))
#define   GPIOA_AFRL                                 *((u32 *)(GPIOA_BASE_ADDRESS + 0x20))
#define   GPIOA_AFRH                                 *((u32 *)(GPIOA_BASE_ADDRESS + 0x24))


                    /* REGISTERS ADDRESSES FOR PORTB  */

#define   GPIOB_MODER                                *((u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define   GPIOB_OTYPER                               *((u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define   GPIOB_OSPEEDER                             *((u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define   GPIOB_PUPDR                                *((u32 *)(GPIOB_BASE_ADDRESS + 0x0c))
#define   GPIOB_IDR                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define   GPIOB_ODR                                  *((u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define   GPIOB_BSRR                                 *((u32 *)(GPIOB_BASE_ADDRESS + 0x18))
#define   GPIOB_LCKR                                 *((u32 *)(GPIOB_BASE_ADDRESS + 0x1c))
#define   GPIOB_AFRL                                 *((u32 *)(GPIOB_BASE_ADDRESS + 0x20))
#define   GPIOB_AFRH                                 *((u32 *)(GPIOB_BASE_ADDRESS + 0x24))



                   /* REGISTERS ADDRESSES FOR PORTC  */

#define   GPIOC_MODER                                *((u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define   GPIOC_OTYPER                               *((u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define   GPIOC_OSPEEDER                             *((u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define   GPIOC_PUPDR                                *((u32 *)(GPIOC_BASE_ADDRESS + 0x0c))
#define   GPIOC_IDR                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define   GPIOC_ODR                                  *((u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define   GPIOC_BSRR                                 *((u32 *)(GPIOC_BASE_ADDRESS + 0x18))
#define   GPIOC_LCKR                                 *((u32 *)(GPIOC_BASE_ADDRESS + 0x1c))
#define   GPIOC_AFRL                                 *((u32 *)(GPIOC_BASE_ADDRESS + 0x20))
#define   GPIOC_AFRH                                 *((u32 *)(GPIOC_BASE_ADDRESS + 0x24))


                /* REGISTERS ADDRESSES FOR PORTD  */

#define   GPIOD_MODER                                *((u32 *)(GPIOD_BASE_ADDRESS + 0x00))
#define   GPIOD_OTYPER                               *((u32 *)(GPIOD_BASE_ADDRESS + 0x04))
#define   GPIOD_OSPEEDER                             *((u32 *)(GPIOD_BASE_ADDRESS + 0x08))
#define   GPIOD_PUPDR                                *((u32 *)(GPIOD_BASE_ADDRESS + 0x0c))
#define   GPIOD_IDR                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x10))
#define   GPIOD_ODR                                  *((u32 *)(GPIOD_BASE_ADDRESS + 0x14))
#define   GPIOD_BSRR                                 *((u32 *)(GPIOD_BASE_ADDRESS + 0x18))
#define   GPIOD_LCKR                                 *((u32 *)(GPIOD_BASE_ADDRESS + 0x1c))
#define   GPIOD_AFRL                                 *((u32 *)(GPIOD_BASE_ADDRESS + 0x20))
#define   GPIOD_AFRH                                 *((u32 *)(GPIOD_BASE_ADDRESS + 0x24))



                   /* REGISTERS ADDRESSES FOR PORTE  */

#define   GPIOE_MODER                                *((u32 *)(GPIOE_BASE_ADDRESS + 0x00))
#define   GPIOE_OTYPER                               *((u32 *)(GPIOE_BASE_ADDRESS + 0x04))
#define   GPIOE_OSPEEDER                             *((u32 *)(GPIOE_BASE_ADDRESS + 0x08))
#define   GPIOE_PUPDR                                *((u32 *)(GPIOE_BASE_ADDRESS + 0x0c))
#define   GPIOE_IDR                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x10))
#define   GPIOE_ODR                                  *((u32 *)(GPIOE_BASE_ADDRESS + 0x14))
#define   GPIOE_BSRR                                 *((u32 *)(GPIOE_BASE_ADDRESS + 0x18))
#define   GPIOE_LCKR                                 *((u32 *)(GPIOE_BASE_ADDRESS + 0x1c))
#define   GPIOE_AFRL                                 *((u32 *)(GPIOE_BASE_ADDRESS + 0x20))
#define   GPIOE_AFRH                                 *((u32 *)(GPIOE_BASE_ADDRESS + 0x24))



                 /* REGISTERS ADDRESSES FOR PORTF  */

#define   GPIOF_MODER                                *((u32 *)(GPIOF_BASE_ADDRESS + 0x00))
#define   GPIOF_OTYPER                               *((u32 *)(GPIOF_BASE_ADDRESS + 0x04))
#define   GPIOF_OSPEEDER                             *((u32 *)(GPIOF_BASE_ADDRESS + 0x08))
#define   GPIOF_PUPDR                                *((u32 *)(GPIOF_BASE_ADDRESS + 0x0c))
#define   GPIOF_IDR                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x10))
#define   GPIOF_ODR                                  *((u32 *)(GPIOF_BASE_ADDRESS + 0x14))
#define   GPIOF_BSRR                                 *((u32 *)(GPIOF_BASE_ADDRESS + 0x18))
#define   GPIOF_LCKR                                 *((u32 *)(GPIOF_BASE_ADDRESS + 0x1c))
#define   GPIOF_AFRL                                 *((u32 *)(GPIOF_BASE_ADDRESS + 0x20))
#define   GPIOF_AFRH                                 *((u32 *)(GPIOF_BASE_ADDRESS + 0x24))


                /* REGISTERS ADDRESSES FOR PORTG  */

#define   GPIOG_MODER                                *((u32 *)(GPIOG_BASE_ADDRESS + 0x00))
#define   GPIOG_OTYPER                               *((u32 *)(GPIOG_BASE_ADDRESS + 0x04))
#define   GPIOG_OSPEEDER                             *((u32 *)(GPIOG_BASE_ADDRESS + 0x08))
#define   GPIOG_PUPDR                                *((u32 *)(GPIOG_BASE_ADDRESS + 0x0c))
#define   GPIOG_IDR                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x10))
#define   GPIOG_ODR                                  *((u32 *)(GPIOG_BASE_ADDRESS + 0x14))
#define   GPIOG_BSRR                                 *((u32 *)(GPIOG_BASE_ADDRESS + 0x18))
#define   GPIOG_LCKR                                 *((u32 *)(GPIOG_BASE_ADDRESS + 0x1c))
#define   GPIOG_AFRL                                 *((u32 *)(GPIOG_BASE_ADDRESS + 0x20))
#define   GPIOG_AFRH                                 *((u32 *)(GPIOG_BASE_ADDRESS + 0x24))

               /* REGISTERS ADDRESSES FOR PORTH  */

#define   GPIOH_MODER                                *((u32 *)(GPIOH_BASE_ADDRESS + 0x00))
#define   GPIOH_OTYPER                               *((u32 *)(GPIOH_BASE_ADDRESS + 0x04))
#define   GPIOH_OSPEEDER                             *((u32 *)(GPIOH_BASE_ADDRESS + 0x08))
#define   GPIOH_PUPDR                                *((u32 *)(GPIOH_BASE_ADDRESS + 0x0c))
#define   GPIOH_IDR                                  *((u32 *)(GPIOH_BASE_ADDRESS + 0x10))
#define   GPIOH_ODR                                  *((u32 *)(GPIOH_BASE_ADDRESS + 0x14))
#define   GPIOH_BSRR                                 *((u32 *)(GPIOH_BASE_ADDRESS + 0x18))
#define   GPIOH_LCKR                                 *((u32 *)(GPIOH_BASE_ADDRESS + 0x1c))
#define   GPIOH_AFRL                                 *((u32 *)(GPIOH_BASE_ADDRESS + 0x20))
#define   GPIOH_AFRH                                 *((u32 *)(GPIOH_BASE_ADDRESS + 0x24))


                                  


#endif     
