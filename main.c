/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "ADC_interface.h"
#include "PWM_interface.h"

#include "Potentiometer.h"
#include "MPU6050.h" 


/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);


#define MOTOR  0
#define IMU    1

#define X			 2
#define Y			 3
#define Z			 4

#define Potentiometer_X			 ADC_PA0
#define Potentiometer_Y			 ADC_PA1
#define Potentiometer_Z			 ADC_PA2

#define MOTOR_X1       			 PWM_PA3
#define MOTOR_X2       			 PWM_PA8

#define MOTOR_Y1		 				 PWM_PA10
#define MOTOR_Y2		 				 PWM_PA11

#define MOTOR_Z1		 				 PWM_PA15
#define MOTOR_Z2		 				 PWM_PB3

int Angle (float Raw, float MAx);

int PID_Controller (int plant , int axis);

void MOTOR_Write (int input, int motor_1, int motor_2);


/* Private user code ---------------------------------------------------------*/
RawData_Def AccelRaw, GyroRaw;
ScaledData_Def AccelScaled, GyroScaled;
int x ;

#define Kp_motor  0.5
#define Ki_motor  0.001
#define Kd_motor  0

#define Kp_IMU    52
#define Ki_IMU    0.002
#define Kd_IMU    0

#define Ts        0.1

float Error_prev_motor_x = 0;
float Error_prev_motor_y = 0;
float Error_prev_motor_z = 0;
float Error_prev_IMU_x = 0;
float Error_prev_IMU_y = 0;
float Error_prev_IMU_z = 0;
	

float A_motor = (Kp_motor + ((Ki_motor * Ts )/2) + (Kd_motor/Ts));
float A_IMU = (Kp_IMU  + ((Ki_IMU * Ts )/2) + (Kd_IMU/Ts));

float B_motor = (((Ki_motor * Ts )/2) - (Kd_motor /Ts));
float B_IMU = (((Ki_IMU * Ts )/2) - (Kd_IMU/Ts));

float C_motor = Ki_motor;
float C_IMU = Ki_IMU;

float IMU_desired_x =  0;
int   MOTOR_desired_x ;
float Position_prev_x = 0;
float Position_prev_Intagral_x = 0;

float IMU_desired_y = -180;
int   MOTOR_desired_y;
float Position_prev_y = 0;
float Position_prev_Intagral_y = 0;

float IMU_desired_z = 0;
int   MOTOR_desired_z;
float Position_prev_z = 0;
float Position_prev_Intagral_z = 0;

float Intagral_prev_motor_x = 0;
float Intagral_prev_motor_y = 0;
float Intagral_prev_motor_z = 0;
float Intagral_prev_IMU_x = 0;
float Intagral_prev_IMU_y = 0;
float Intagral_prev_IMU_z = 0;
	
int MOTOR_INPUT_X     ;
int MOTOR_INPUT_Y     ;
int MOTOR_INPUT_Z     ;


float IMU_X;
float IMU_Y;
float IMU_Z;
	
int main(void)
{
		
  MPU_ConfigTypeDef MpuConfig;
  
  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();
  MX_I2C1_Init();
	
	RCC_voidInitSysClock();                            //Initialize System Clock
	
	RCC_voidEnableClock(RCC_AHB1, RCC_GPIOA);           //Initialize PORTA Clock
	RCC_voidEnableClock(RCC_AHB1, RCC_GPIOB);           //Initialize PORTB Clock
	//RCC_voidEnableClock(RCC_APB2, RCC_ADC1);            //Initialize ADC1 Clock
	RCC_voidEnableClock(RCC_APB2, RCC_TIM1);            //Initialize TIM1 Clock
	RCC_voidEnableClock(RCC_APB1, RCC_TIM2);            //Initialize TIM2 Clock
	
			
  Potentiometer_Init( GPIOA, Potentiometer_X);
	Potentiometer_Init( GPIOA, Potentiometer_Y);
	Potentiometer_Init( GPIOA, Potentiometer_Z);
	
	/*GPIO_voidSetPinDirection(GPIOA, PIN0, GPIO_ANALOG); //Set pin A0 as analog
	SET_GPIO_SPEED(GPIOA, PIN0, GPIO_SPEED_MEDIUM);     //Set PIN A0 speed at 25MHz
	GPIO_SET_PU_PD(GPIOA, PIN0, GPIO_NO_PU_PD);         //Disable pull resistors
	
	GPIO_voidSetPinDirection(GPIOA, PIN1, GPIO_ANALOG); //Set pin A1 as analog
	SET_GPIO_SPEED(GPIOA, PIN1, GPIO_SPEED_MEDIUM);     //Set PIN A1 speed at 25MHz
	GPIO_SET_PU_PD(GPIOA, PIN1, GPIO_NO_PU_PD);         //Disable pull resistors
	
	GPIO_voidSetPinDirection(GPIOA, PIN2, GPIO_ANALOG); //Set pin A2 as analog
	SET_GPIO_SPEED(GPIOA, PIN2, GPIO_SPEED_MEDIUM);     //Set PIN A2 speed at 25MHz
	GPIO_SET_PU_PD(GPIOA, PIN2, GPIO_NO_PU_PD);         //Disable pull resistors
	*/
	GPIO_voidSetPinDirection(GPIOA, PIN3, GPIO_AF);     //Set Pin A3 as Alterntive Function
	SET_GPIO_SPEED(GPIOA, PIN3, GPIO_SPEED_MEDIUM);     //Set Pin A3 speed at 25MHZ
	GPIO_SET_PP_OD(GPIOA, PIN3, GPIO_OUTPUT_PP);        //Set Pin A3 as push pull mode
	PWM_Pin(MOTOR_X1);                                   //Set Pin A3 Alternative Function as PWM
	
	
	GPIO_voidSetPinDirection(GPIOA, PIN8, GPIO_AF);     //Set Pin A8 as Alterntive Function
	SET_GPIO_SPEED(GPIOA, PIN8, GPIO_SPEED_MEDIUM);     //Set Pin A8 speed at 25MHZ
	GPIO_SET_PP_OD(GPIOA, PIN8, GPIO_OUTPUT_PP);        //Set Pin A8 as push pull mode
	PWM_Pin(MOTOR_X2);                                   //Set Pin A8 Alternative Function as PWM
	
	GPIO_voidSetPinDirection(GPIOA, PIN10, GPIO_AF);     //Set Pin A10 as Alterntive Function
	SET_GPIO_SPEED(GPIOA, PIN10, GPIO_SPEED_MEDIUM);     //Set Pin A10 speed at 25MHZ
	GPIO_SET_PP_OD(GPIOA, PIN10, GPIO_OUTPUT_PP);        //Set Pin A10 as push pull mode
	PWM_Pin(MOTOR_Y1);                                   //Set Pin A10 Alternative Function as PWM
	
	GPIO_voidSetPinDirection(GPIOA, PIN11, GPIO_AF);     //Set Pin A11 as Alterntive Function
	SET_GPIO_SPEED(GPIOA, PIN11, GPIO_SPEED_MEDIUM);     //Set Pin A11 speed at 25MHZ
	GPIO_SET_PP_OD(GPIOA, PIN11, GPIO_OUTPUT_PP);        //Set Pin A11 as push pull mode
	PWM_Pin(MOTOR_Y2);                                   //Set Pin A11 Alternative Function as PWM
	
	
	GPIO_voidSetPinDirection(GPIOA, PIN15, GPIO_AF);     //Set Pin A15 as Alterntive Function
	SET_GPIO_SPEED(GPIOA, PIN15, GPIO_SPEED_MEDIUM);     //Set Pin A15 speed at 25MHZ
	GPIO_SET_PP_OD(GPIOA, PIN15, GPIO_OUTPUT_PP);        //Set Pin A15 as push pull mode
	PWM_Pin(MOTOR_Z1);                                   //Set Pin A15 Alternative Function as PWM
	
	GPIO_voidSetPinDirection(GPIOB, PIN3, GPIO_AF);     //Set Pin B3 as Alterntive Function
	SET_GPIO_SPEED(GPIOB, PIN3, GPIO_SPEED_MEDIUM);     //Set Pin B3 speed at 25MHZ
	GPIO_SET_PP_OD(GPIOB, PIN3, GPIO_OUTPUT_PP);        //Set Pin B3 as push pull mode
	PWM_Pin(MOTOR_Z2);                                   //Set Pin B3 Alternative Function as PWM

  MADC_voidInit();                                    //Initialize ADC1 Module
	PWM_Init(TIMER1);                                   //Initialize TIM1 Module
	PWM_Init(TIMER2);                                   //Initialize TIM2 Module


	//1. Initialise the MPU6050 module and I2C
	MPU6050_Init(&hi2c1);
	//2. Configure Accel and Gyro parameters
	MpuConfig.Accel_Full_Scale = AFS_SEL_4g;
	MpuConfig.ClockSource = Internal_8MHz;
	MpuConfig.CONFIG_DLPF = DLPF_184A_188G_Hz;
	MpuConfig.Gyro_Full_Scale = FS_SEL_500;
	MpuConfig.Sleep_Mode_Bit = 0;  //1: sleep mode, 0: normal mode
	MPU6050_Config(&MpuConfig);

	
  while (1)
  {
	
		MPU6050_Get_Accel_Scale(&AccelScaled);
	
		IMU_X = Angle(AccelScaled.x , 180);
		IMU_Y = Angle(AccelScaled.y , 180);
		IMU_Z = Angle(AccelScaled.z , 180);
		
		MOTOR_desired_x = PID_Controller( IMU , X);
		MOTOR_desired_y = PID_Controller( IMU , Y);
		MOTOR_desired_z = PID_Controller( IMU , Z);

		MOTOR_INPUT_X = PID_Controller( MOTOR , X);
		MOTOR_INPUT_Y = PID_Controller( MOTOR , Y);
		MOTOR_INPUT_Z = PID_Controller( MOTOR , Z);
		
		MOTOR_Write(MOTOR_INPUT_X, MOTOR_X1, MOTOR_X2);
		MOTOR_Write(MOTOR_INPUT_Y, MOTOR_Y1, MOTOR_Y2);
		MOTOR_Write(MOTOR_INPUT_Z, MOTOR_Z1, MOTOR_Z2);

		HAL_Delay(10);
  }
}

int Angle (float Raw, float MAX)
{		
   return (Raw * (MAX/1000));
}

int PID_Controller (int plant , int axis)
{
	switch (plant)
  {
		case IMU :
			switch (axis)
			{
				case X: 
				{
					
					float Position_Act_x = Angle (AccelScaled.x , 180) ;

          if ( ( (Position_Act_x > (IMU_desired_x -5)) && (Position_Act_x  < (IMU_desired_x +5) )) )
          {
              Position_Act_x = IMU_desired_x;
          }
          
          float Error_x = IMU_desired_x - Position_Act_x;
					int Control_Output = A_IMU * Error_x + B_IMU * Error_prev_IMU_x + C_IMU * Intagral_prev_IMU_x;
					
					Intagral_prev_IMU_x = Intagral_prev_IMU_x + ( ((Error_x + Error_prev_IMU_x)/2) * Ts );
					Error_prev_IMU_x = Error_x;
					
					return Control_Output;
				}
				case Y: 
				{
					float Position_Act_y = Angle (AccelScaled.y , 180);
          
          if ( ( (Position_Act_y > (IMU_desired_y -5)) && (Position_Act_y  < (IMU_desired_y +5) )) )
          {
              Position_Act_y = IMU_desired_y;
          }
          
          float Error_y = IMU_desired_y - Position_Act_y;
          
					int Control_Output = A_IMU * Error_y + B_IMU * Error_prev_IMU_y + C_IMU * Intagral_prev_IMU_y;
					
					Intagral_prev_IMU_y = Intagral_prev_IMU_y + ( ((Error_y + Error_prev_IMU_y)/2) * Ts );
					Error_prev_IMU_y = Error_y;
					
					return Control_Output;
				}
				case Z: 
				{
					
					
					float Position_Act_z = Angle (AccelScaled.z , 180);

          if ( ( (Position_Act_z > (IMU_desired_z -5)) && (Position_Act_z  < (IMU_desired_z +5) )) )
          {
              Position_Act_z = IMU_desired_z;
          }

          
          float Error_z = IMU_desired_z - Position_Act_z;
          
					int Control_Output = A_IMU * Error_z + B_IMU * Error_prev_IMU_z + C_IMU * Intagral_prev_IMU_z;
					
					Intagral_prev_IMU_z = Intagral_prev_IMU_z + ( ((Error_z + Error_prev_IMU_z)/2) * Ts );
					Error_prev_IMU_z = Error_z;
					
					return Control_Output;
				}
			}
		case MOTOR :
			switch (axis)
			{
				case X: 
				{
					float Position_Act_x = Get_Angle (Potentiometer_X, 180.0);
					
					if ( ( (Position_Act_x > (MOTOR_desired_x -10)) && (Position_Act_x  < (MOTOR_desired_x +10) )) )
          {
              Position_Act_x = MOTOR_desired_x;
          }
          
					float Error_x = MOTOR_desired_x - Position_Act_x;
					int Control_Output = A_motor * Error_x + B_motor * Error_prev_motor_x + C_motor * Intagral_prev_motor_x;
					
					Intagral_prev_motor_x = Intagral_prev_motor_x + ( ((Error_x + Error_prev_motor_x)/2) * Ts );
					Error_prev_motor_x = Error_x;
					
					return Control_Output;
				}
				case Y: 
				{
					float Position_Act_y =  Get_Angle (Potentiometer_Y, 180.0);

					if ( ( (Position_Act_y > (MOTOR_desired_y -10)) && (Position_Act_y  < (MOTOR_desired_y +10) )) )
          {
              Position_Act_y = MOTOR_desired_y;
          }

					float Error_y = MOTOR_desired_y - Position_Act_y;
					int Control_Output = A_motor * Error_y + B_motor * Error_prev_motor_y + C_motor * Intagral_prev_motor_y;
					
					Intagral_prev_motor_y = Intagral_prev_motor_y + ( ((Error_y + Error_prev_motor_y)/2) * Ts );
					Error_prev_motor_y = Error_y;
					
					return Control_Output;
				}
				case Z: 
				{
					float Position_Act_z = Get_Angle (Potentiometer_Z, 180.0);
					
					if ( ( (Position_Act_z > (MOTOR_desired_z -10)) && (Position_Act_z  < (MOTOR_desired_z +10) )) )
          {
              Position_Act_z = MOTOR_desired_z;
          }
          
					
					float Error_z = MOTOR_desired_z - Position_Act_z;
					int Control_Output = A_motor * Error_z + B_motor * Error_prev_motor_z + C_motor * Intagral_prev_motor_z;
					
					Intagral_prev_motor_z = Intagral_prev_motor_z + ( ((Error_z + Error_prev_motor_z)/2) * Ts );
					Error_prev_motor_z = Error_z;
					
					return Control_Output;
				}
			}
	}
}

void MOTOR_Write (int input, int motor_1, int motor_2)
{
		if (input < 0 )
		{
			input = (input)* -1 ;
			
			//MOTOR_INPUT_X = input;
			
			if (input > 4000)
			{
				input = 4000;
			}
			PWM_PinWrite(motor_1, 0, 4095);
			PWM_PinWrite(motor_2, input, 4095);
			
  	}
		else if (input >= 0)
		{
			if (input > 4000)
			{
				input = 4000;
			}
			PWM_PinWrite(motor_1, input, 4095);
			PWM_PinWrite(motor_2, 0, 4095);
			
		}
}



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
