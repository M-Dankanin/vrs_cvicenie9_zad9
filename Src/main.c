/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "i2c.h"
#include "tim.h"
#include "gpio.h"
#include "display.h"
#include "math.h"
#include <string.h>

#include "hts221.h"
#include "lps25hb.h"

float temperature = 0;
float humidity = 0;
float pressure = 0;
float altitude = 0;
extern uint64_t disp_time;

uint64_t saved_time;
int string_pos = 0;
int direction = 1;
int new_state = 1;
int state = 1;
int string_len;

void SystemClock_Config(void);

int main(void)
{

  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);
  SystemClock_Config();
  MX_GPIO_Init();
  MX_I2C1_Init();
  setSegments();
  setDigits();

  LL_mDelay(2000);

  resetDigits();
  resetSegments();
  hts221_init();
  lps25hb_init();

  MX_TIM3_Init();

  char string[20] = "";
  while (1)
  {
		if (disp_time > (saved_time + 500)) {

			if (state != new_state) {
				string_pos = 0;
				direction = 1;
				state = new_state;
			}

			if (state == 1) {
				temperature = hts221_get_temperature() * 1.00f;
				sprintf(string, "TEMP_%3.1f", temperature);
				string_len = 9;
			}
			if (state == 2) {
				humidity = hts221_get_humidity() * 1.00f;
				sprintf(string, "HUM_%2.0f", humidity);
				string_len = 6;
			}
			if (state == 3) {
				pressure = lps25hb_get_pressure() * 1.00f;
				sprintf(string, "BAR_%6.2f", pressure);
				string_len = 11;
			}
			if (state == 4) {
				altitude = get_altitude() * 1.00f;
				sprintf(string, "ALT_%5.1f", altitude);
				string_len = 10;
			}

			displayString(&string[string_pos]);
			string_pos += direction;
			saved_time = disp_time;

			if (string_pos > string_len - 5) {
				direction = -1;
			}
			if (string_pos == 0) {
				direction = 1;
			}
		}
	}

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

  if(LL_FLASH_GetLatency() != LL_FLASH_LATENCY_0)
  {
  Error_Handler();  
  }
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {
    
  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {
  
  }
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK); 
  LL_SetSystemCoreClock(8000000);
  LL_RCC_SetI2CClockSource(LL_RCC_I2C1_CLKSOURCE_HSI);
  LL_SYSTICK_EnableIT();
}

/* USER CODE BEGIN 4 */


float get_altitude()
{
	//https://keisan.casio.com/exec/system/1224585971

	float pressure_alt = lps25hb_get_pressure();
	float temperature_alt = hts221_get_temperature();
	float altitude_alt;

	altitude_alt = ((powf((1013.25/pressure_alt),1/5.257)-1)*(temperature_alt+273.15))/0.0065;

	return altitude_alt;
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
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
