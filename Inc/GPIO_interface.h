/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 11 December 2020                                 */
/* Version : V02.5                                            */
/*************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
#include "STD_TYPES.h"
  /* for GPIO_Value  */

#define      GPIO_HIGH    1
#define      GPIO_LOW     0

          /* GPIO   Ports */
		  
#define      GPIOA        0
#define      GPIOB        1
#define      GPIOC        2
#define      GPIOD        3
#define      GPIOE        4
#define      GPIOF        5
#define      GPIOG        6
#define      GPIOH        7


         /* PINs Numbers */
		 
#define      PIN0         0
#define      PIN1         1
#define      PIN2         2
#define      PIN3         3
#define      PIN4         4
#define      PIN5         5
#define      PIN6         6
#define      PIN7         7
#define      PIN8         8
#define      PIN9         9
#define      PIN10        10
#define      PIN11        11
#define      PIN12        12
#define      PIN13        13
#define      PIN14        14
#define      PIN15        15
          
		  /*************************************** GPIO  Modes   *******************************/
		  
		  /*     MODER  for  GPIO_MODE    */
 
#define     GPIO_INPUT                                    0           /* input mode */      
#define     GPIO_OUTPUT                                   1           /* output mode */     
#define     GPIO_AF                                       2           /* Alternate functon mode */    
#define     GPIO_ANALOG                                   3           /* Analog mode */

/*Use the following Macros with SET_GPIO_SPEED_PP_OD*/
/*   OTYPER   for  GPIO_PP_OD    */
             
#define     GPIO_OUTPUT_PP                                0           /* output push pull  */       
#define     GPIO_OUTPUT_OD                                1           /* output open drain */
                                       

           /* OSPEEDR   for     GPIO_Speed  */
		   
#define     GPIO_SPEED_LOW                                0           /* low speed      2   MHz             */
#define     GPIO_SPEED_MEDIUM                             1           /* medium speed   25  MHz            */
#define     GPIO_SPEED_FAST                               2           /* fast speed     50  MHz            */         
#define     GPIO_SPEED_HIGH                               3           /* High speed     100 MHz            */

            


            /*  PUPDR    for  GPIO_PU_PD   */
			
#define     GPIO_NO_PU_PD                                 0           /* NO pull up, pull down */ 
#define     GPIO_PU                                       1           /*  pull up */
#define     GPIO_PD                                       2           /* pull down */


                          /* Functions */

     /* set pin direction :  input/ output/ analog / AF*/
	 
void GPIO_voidSetPinDirection(u8 GPIO_PORT , u8 GPIO_PIN , u8 GPIO_Mode );
void SET_GPIO_SPEED( u8 GPIO_PORT , u8 GPIO_PIN ,u8 GPIO_Speed );    //choose speed (Low, Medium , Fast, High)
 void GPIO_SET_PU_PD (u8 GPIO_PORT , u8 GPIO_PIN, u8 GPIO_PU_PD);  //Use with Input Pin Configuration
void GPIO_SET_PP_OD (u8 GPIO_PORT , u8 GPIO_PIN, u8 GPIO_PP_OD);  //choose pull up (0 for GND , 1 for Vcc) or open drain ( 0 for GND , 1 for Floating)
              /* set pin value  : High or low    */
	
void GPIO_voidSetPinValue(u8 GPIO_PORT , u8 GPIO_PIN , u8 GPIO_Value);     //Similar to DigitalWrite in Arduino

              /*  get pin value , read only , contains IDR (input data register) to return the input value of the corresponding I/O Port */
			  
u8 MGPIO_u8GetPinValue(u8 GPIO_PORT , u8 GPIO_PIN );             //Similar To DigitalRead in Arduino

/*Version 2.5 Extra Function*/
void GPIO_Set_AF(u8 GPIO_PORT , u8 GPIO_PIN , u8 AFIO_ID );    //used to set Alternative function to be used in AFIO mode... Check Datasheet to get AFIO_ID
  

#endif
