/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "software_timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_TIM2_Init(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_TIM2_Init();
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */



  void LED_7SEG_MODE(int a, int b, int c, int d, int e, int f, int g){
//	better with switch case
	HAL_GPIO_WritePin ( LED_7SEG_A_GPIO_Port , LED_7SEG_A_Pin, a );
	HAL_GPIO_WritePin ( LED_7SEG_B_GPIO_Port , LED_7SEG_B_Pin, b );
	HAL_GPIO_WritePin ( LED_7SEG_C_GPIO_Port , LED_7SEG_C_Pin, c );
	HAL_GPIO_WritePin ( LED_7SEG_D_GPIO_Port , LED_7SEG_D_Pin, d );
	HAL_GPIO_WritePin ( LED_7SEG_E_GPIO_Port , LED_7SEG_E_Pin, e );
	HAL_GPIO_WritePin ( LED_7SEG_F_GPIO_Port , LED_7SEG_F_Pin, f );
	HAL_GPIO_WritePin ( LED_7SEG_G_GPIO_Port , LED_7SEG_G_Pin, g );
  }

  void  display7SEG(int num){
	  switch(num){
	  	  case 0:
	  		LED_7SEG_MODE(0,0,0,0,0,0,1);
	  		break;
	  	  case 1:
	  		LED_7SEG_MODE(1,0,0,1,1,1,1);
	  		break;
	  	  case 2:
	  		LED_7SEG_MODE(0,0,1,0,0,1,0);
			break;
	  	  case 3:
	  		LED_7SEG_MODE(0,0,0,0,1,1,0);
			break;
	  	  case 4:
	  		LED_7SEG_MODE(1,0,0,1,1,0,0);
	  		break;
	  	  case 5:
	  		LED_7SEG_MODE(0,1,0,0,1,0,0);
	  		break;
	  	  case 6:
	  		LED_7SEG_MODE(0,1,0,0,0,0,0);
	  		break;
	  	  case 7:
	  		LED_7SEG_MODE(0,0,0,1,1,1,1);
	  		break;
	  	  case 8:
	  		LED_7SEG_MODE(0,0,0,0,0,0,0);
	  		break;
	  	  case 9:
	  		LED_7SEG_MODE(0,0,0,0,1,0,0);
	  		break;
	  }
  }

//  const int MAX_LED = 4;

  int led_buffer[4] = {1, 2, 3, 4};
  void update7SEG(int index){
	  switch(index){
	  case 0:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN0_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN3_Pin, 1);
		display7SEG(led_buffer[0]);
		break;
	  case 1:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN1_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN3_Pin, 1);
		display7SEG(led_buffer[1]);
		break;
	  case 2:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN2_Pin, 0);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN3_Pin, 1);
		display7SEG(led_buffer[2]);
		break;
	  case 3:
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN0_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN1_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN2_Pin, 1);
		HAL_GPIO_WritePin(GPIOA, LED_7SEG_EN3_Pin, 0);
		display7SEG(led_buffer[3]);
		break;
	  default:
		  break;
	  }
  }

  setTimer1(50);
  setTimer2(100);
  int index_led = 0;
  int state = 0;
  while (1)
  {
	  if(timer1_flag == 1){
	  		setTimer1(50);
	  		switch(state){
	  		case 0:
	  			update7SEG(index_led++);
	  			state = 1;
	  			break;
	  		case 1:
	  			update7SEG(index_led++);
	  			state = 2;
	  			break;
	  		case 2:
	  			update7SEG(index_led++);
	  			state = 3;
	  			break;
	  		case 3:
	  			update7SEG(index_led++);
	  			state = 0;
	  			index_led = 0;
	  			break;
	  		default:
	  			break;
	  		}
	  	}

	  if(timer2_flag == 1){
		  setTimer2(100);
		  HAL_GPIO_TogglePin(GPIOA, LED_RED_DOT_Pin);
	  }
	}
}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	/* USER CODE END 3 */


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_DOT_Pin|LED_RED_Pin|LED_7SEG_EN0_Pin|LED_7SEG_EN1_Pin
                          |LED_7SEG_EN2_Pin|LED_7SEG_EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_7SEG_A_Pin|LED_7SEG_B_Pin|LED_7SEG_C_Pin|LED_7SEG_D_Pin
                          |LED_7SEG_E_Pin|LED_7SEG_F_Pin|LED_7SEG_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_DOT_Pin LED_RED_Pin LED_7SEG_EN0_Pin LED_7SEG_EN1_Pin
                           LED_7SEG_EN2_Pin LED_7SEG_EN3_Pin */
  GPIO_InitStruct.Pin = LED_RED_DOT_Pin|LED_RED_Pin|LED_7SEG_EN0_Pin|LED_7SEG_EN1_Pin
                          |LED_7SEG_EN2_Pin|LED_7SEG_EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_7SEG_A_Pin LED_7SEG_B_Pin LED_7SEG_C_Pin LED_7SEG_D_Pin
                           LED_7SEG_E_Pin LED_7SEG_F_Pin LED_7SEG_G_Pin */
  GPIO_InitStruct.Pin = LED_7SEG_A_Pin|LED_7SEG_B_Pin|LED_7SEG_C_Pin|LED_7SEG_D_Pin
                          |LED_7SEG_E_Pin|LED_7SEG_F_Pin|LED_7SEG_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
	void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim){
		timer1Run();
		timer2Run();
	}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
