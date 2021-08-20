/***************************************************************/
/* Author  :  Omaima                                          */
/* Date    : 11 December 2020                                 */
/* Version : V02.5                                            */
/*************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

 void GPIO_voidSetPinDirection(u8 GPIO_PORT , u8 GPIO_PIN , u8 GPIO_Mode ) 
 {
   switch (GPIO_PORT)
   { 
       case GPIOA :
	               
				   GPIOA_MODER &=~((0x3UL)<<(GPIO_PIN*2)); 
				   GPIOA_MODER |=((GPIO_Mode)<<(GPIO_PIN*2));
				   
				   if((GPIO_PIN <=7)&&(GPIO_Mode == GPIO_AF))
				   {
				      GPIOA_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOA_AFRL |=((GPIO_Mode)<<(GPIO_PIN*4));
                    }
                   else if((GPIO_PIN <=15)&&(GPIO_Mode == GPIO_AF))
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOA_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOA_AFRH |=((GPIO_Mode)<<(GPIO_PIN*4));
					} 
				   break;
	   case GPIOB :
				   GPIOB_MODER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOB_MODER |=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
	               
	   case GPIOC :
				   GPIOC_MODER&=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOC_MODER|=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
	   case GPIOD :
				   GPIOD_MODER&=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOD_MODER|=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
	   case GPIOE : 
				   GPIOE_MODER&=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOE_MODER|=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
	   case GPIOF :
				   GPIOF_MODER&=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOF_MODER|=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
	   case GPIOG :
				   GPIOG_MODER&=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOG_MODER|=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
	   case GPIOH :
				   GPIOH_MODER&=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOH_MODER|=((GPIO_Mode)<<(GPIO_PIN*2));
				   break;
				default : break;
 }
 }
 
 void SET_GPIO_SPEED( u8 GPIO_PORT , u8 GPIO_PIN ,u8 GPIO_Speed )
 {
 switch (GPIO_PORT)
   { 
       case GPIOA :
				   GPIOA_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOA_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	 case GPIOB :
				   GPIOB_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOB_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	 case GPIOC :
				   GPIOC_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOC_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	   case GPIOD :			  
				   GPIOD_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOD_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	   case GPIOE : 
				   GPIOE_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOE_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	   case GPIOF : 
				   GPIOF_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOF_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	   case GPIOG :
				   GPIOG_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOG_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
				   break;
	   case GPIOH :
				   GPIOH_OSPEEDER &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOH_OSPEEDER |=((GPIO_Speed)<<(GPIO_PIN*2));
		           break;
				   default: break;
 }
 }
 
 
 void GPIO_SET_PP_OD (u8 GPIO_PORT , u8 GPIO_PIN, u8 GPIO_PP_OD)
 {
 switch (GPIO_PORT)
   { 
       case GPIOA :
				   GPIOA_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				   GPIOA_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));
				   break;
	  case GPIOB :
				 GPIOB_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				 GPIOB_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));  
				   break;             
	   case GPIOC :
				 GPIOC_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				 GPIOC_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));  
				   break;
	   case GPIOD :
				  GPIOD_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				  GPIOD_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));
				   break;
	   case GPIOE :
				   GPIOE_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				   GPIOE_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));
				   break;
	   case GPIOF :
				   GPIOF_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				   GPIOF_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));
				   break;
	   case GPIOG :
				   GPIOG_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				   GPIOG_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));
				   break;
	   case GPIOH :
				   GPIOH_OTYPER &=~((0x1UL)<<(GPIO_PIN));
				   GPIOH_OTYPER |=((GPIO_PP_OD)<<(GPIO_PIN));
				   break;
				default : break;
 }
 }
 void GPIO_SET_PU_PD (u8 GPIO_PORT , u8 GPIO_PIN, u8 GPIO_PU_PD)
 {
 switch (GPIO_PORT)
   { 
       case GPIOA :
				   GPIOA_PUPDR &= ~((0x3UL)<<(GPIO_PIN*2));
				   GPIOA_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				   break;   
	   case GPIOB :
				   GPIOB_PUPDR &= ~((0x3UL)<<(GPIO_PIN*2));
				   GPIOB_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				   break;
	   case GPIOC :
				   GPIOC_PUPDR &= ~((0x3UL)<<(GPIO_PIN*2));
				   GPIOC_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				   break;
	   case GPIOD :
				   GPIOD_PUPDR &= ~((0x3UL)<<(GPIO_PIN*2));
				   GPIOD_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				   break;
	   case GPIOE : 
				   GPIOE_PUPDR &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOE_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				   break;
	   case GPIOF :			   
				   GPIOF_PUPDR &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOF_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				  
				   break;
	   case GPIOG :
				   GPIOG_PUPDR &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOG_PUPDR |= ((GPIO_PU_PD)<<(GPIO_PIN*2));
				   break;
	   case GPIOH :  
				   GPIOH_PUPDR &=~((0x3UL)<<(GPIO_PIN*2));
				   GPIOH_PUPDR |=((GPIO_PU_PD)<<(GPIO_PIN*2));
				   
				   break;
				default : break;
	   
 }
 }
 
 
 
void GPIO_voidSetPinValue(u8 GPIO_PORT , u8 GPIO_PIN , u8 GPIO_Value)
{
     switch(GPIO_PORT)
	 {  
	      case GPIOA :
                       if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOA_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOA_ODR, GPIO_PIN);						
                        }
						break;
			case GPIOB :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOB_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOB_ODR, GPIO_PIN);						
                        }
						break;
	        case GPIOC :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOC_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOC_ODR, GPIO_PIN);						
                        }
						break;
		    case GPIOD :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOD_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOD_ODR, GPIO_PIN);						
                        }
						break;
			case GPIOE :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOE_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOE_ODR, GPIO_PIN);						
                        }
						break;	
			case GPIOF :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOF_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOF_ODR, GPIO_PIN);						
                        }
						break;	
			case GPIOG :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOG_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOG_ODR, GPIO_PIN);						
                        }
						break;	
			case GPIOH :			
						if(GPIO_Value == GPIO_HIGH)
                        {
                            SET_BIT(GPIOH_ODR , GPIO_PIN);
                        }
                       else if(GPIO_Value == GPIO_LOW)
                        {
                            CLR_BIT(GPIOH_ODR, GPIO_PIN);						
                        }
						break;
            default: break;						
}
}

u8 MGPIO_u8GetPinValue(u8 GPIO_PORT , u8 GPIO_PIN )
{
    u8 LOCAL_Result = 0 ;
	switch(GPIO_PORT)
	 {
	 case GPIOA : 
	              LOCAL_Result = GET_BIT(GPIOA_IDR , GPIO_PIN );
				  break;
	 case GPIOB : 
	              LOCAL_Result = GET_BIT(GPIOB_IDR , GPIO_PIN );
				  break;
	 case GPIOC : 
	              LOCAL_Result = GET_BIT(GPIOC_IDR , GPIO_PIN );
				  break;
	case GPIOD : 
	              LOCAL_Result = GET_BIT(GPIOD_IDR , GPIO_PIN );
				  break;
	case GPIOE : 
	              LOCAL_Result = GET_BIT(GPIOE_IDR , GPIO_PIN );
				  break;
	case GPIOF : 
	              LOCAL_Result = GET_BIT(GPIOF_IDR , GPIO_PIN );
				  break;	
    case GPIOG : 
	              LOCAL_Result = GET_BIT(GPIOG_IDR , GPIO_PIN );
				  break;	
    case GPIOH : 
	              LOCAL_Result = GET_BIT(GPIOH_IDR , GPIO_PIN );
				  break;	
                 default : break;				  
} 
   return LOCAL_Result;
   }
   
   /*Version 2.5 Extra Code*/
   
   void GPIO_Set_AF(u8 GPIO_PORT , u8 GPIO_PIN , u8 AFIO_ID ){
	   switch (GPIO_PORT)
   { 
       case GPIOA :
				   if(GPIO_PIN <=7)
				   {
				      GPIOA_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOA_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOA_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOA_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOB :
				   if(GPIO_PIN <=7)
				   {
				      GPIOB_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOB_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOB_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOB_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOC :
				   if(GPIO_PIN <=7)
				   {
				      GPIOC_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOC_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOC_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOC_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOD :
				   if(GPIO_PIN <=7)
				   {
				      GPIOD_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOD_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOD_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOD_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOE :
				   if(GPIO_PIN <=7)
				   {
				      GPIOE_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOE_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOE_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOE_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOF :
				   if(GPIO_PIN <=7)
				   {
				      GPIOF_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOF_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOF_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOF_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOG :
				   if(GPIO_PIN <=7)
				   {
				      GPIOG_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOG_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOG_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOG_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		case GPIOH :
				   if(GPIO_PIN <=7)
				   {
				      GPIOH_AFRL &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOH_AFRL |=((AFIO_ID)<<(GPIO_PIN*4));
                    }
                   else if(GPIO_PIN <=15)
                    {
                      GPIO_PIN = GPIO_PIN-8 ;
					  GPIOH_AFRH &=~((0xFUL)<<(GPIO_PIN*4));
					  GPIOH_AFRH |=((AFIO_ID)<<(GPIO_PIN*4));
					} 
				   break;
		default: break;
   }
   }
   
   
   