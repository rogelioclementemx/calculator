#include "main.h"

uint32_t previousTime = 0;
uint32_t currentTime = 0;

int key, keyboardNumber, total, operation;

int D1 = 0x70, D2 = 0x60, D3 = 0x50, D4 = 0x40, D5 = 0x30, D6 = 0x20, D7 = 0x10, D8 = 0x00;
int numeros[10] = {0x0, 0x01, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9};

void SystemClock_Config(void);
static void MX_GPIO_Init(void);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);

void displayNumber(int number);
void setDisplay(int dig1, int dig2, int dig3, int dig4, int dig5, int dig6, int dig7, int dig8);

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();

  while (1)
  {
	  displayNumber(keyboardNumber);
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  currentTime = HAL_GetTick();

  if (currentTime - previousTime > 250)
  {
    switch (GPIO_Pin)
    {
      case GPIO_PIN_0:
        GPIOA->ODR=0xF0;

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==0)
        {
          operation = 4; // Division
          
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==0)
        {
          operation = 3; // Multiplicacion
          
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==0)
        {
          operation = 2; // Resta
          
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0)==0)
        {
          operation = 1; // Suma
        }

        total = 0;
        total = keyboardNumber;
        key = 0;
        keyboardNumber = 0;

        GPIOA->ODR=0x00;
        break;
      case GPIO_PIN_1:
    	GPIOA->ODR=0xF0;

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)
        {
          switch (operation)
          {
            case 1:
              keyboardNumber = total + keyboardNumber;
              break;
            case 2:
              keyboardNumber = total - keyboardNumber;
              break;
            case 3:
              keyboardNumber = total * keyboardNumber;
              break;
            case 4:
              keyboardNumber = total / keyboardNumber;      
              break;
          }          
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)
        {
          key = 9;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)
        {
          key = 6;
          
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)==0)
        {
          key = 3;
          
        }

        GPIOA->ODR=0x00;
        break;
      case GPIO_PIN_2:
        GPIOA->ODR=0xF0;

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)==0)
        {
          key = 0;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)==0)
        {
          key = 8;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)==0)
        {
          key = 5;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)==0)
        {
          key = 2;
        }

        GPIOA->ODR=0x00;
        break;
      case GPIO_PIN_3:
        GPIOA->ODR=0xF0;

        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)==0)
        {
          keyboardNumber = 0;
          key = 0;
          operation = 0;
          total = 0;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)==0)
        {
          key = 7;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)==0)
        {
          key = 4;
        }
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)==0)
        {
          key = 1;
        }

        GPIOA->ODR=0x00;
        break;
    }
    keyboardNumber = (keyboardNumber%10000000)*10 + key;
    previousTime = currentTime;
  }
}

void displayNumber(int number)
{
	int dig1,dig2,dig3,dig4,dig5,dig6,dig7,dig8;

	dig8 = number%10;
	dig7 = (number%100)/10;
	dig6 = (number%1000)/100;
	dig5 = (number%10000)/1000;
	dig4 = (number%100000)/10000;
	dig3 = (number%1000000)/100000;
	dig2 = (number%10000000)/1000000;
	dig1 = (number%100000000)/10000000;

	setDisplay(dig1,dig2,dig3,dig4,dig5,dig6,dig7,dig8);
}

void setDisplay(int dig1, int dig2, int dig3, int dig4, int dig5, int dig6, int dig7, int dig8)
{
	GPIOC->ODR = D8 + numeros[dig8];
	HAL_Delay(1);

	GPIOC->ODR = D7 + numeros[dig7];
	HAL_Delay(1);

	GPIOC->ODR = D6 + numeros[dig6];
	HAL_Delay(1);

	GPIOC->ODR = D5 + numeros[dig5];
	HAL_Delay(1);

	GPIOC->ODR = D4 + numeros[dig4];
	HAL_Delay(1);

	GPIOC->ODR = D3 + numeros[dig3];
	HAL_Delay(1);


	GPIOC->ODR = D2 + numeros[dig2];
	HAL_Delay(1);

	GPIOC->ODR = D1 + numeros[dig1];
	HAL_Delay(1);
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC0 PC1 PC2 PC3
                           PC4 PC5 PC6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB2 PB3 */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
