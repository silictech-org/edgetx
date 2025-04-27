/*
 * Copyright (C) EdgeTx
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "board.h"
#include "hal/gpio.h"
#include "stm32_gpio.h"
#include "stm32_timer.h"
#include "stm32_hal_ll.h"
#include "stm32_hal.h"
#include "stm32h7xx_hal_conf.h"
// extern void LCD_SetBrightness(uint32_t);

/* LPTimer handler declaration */
static LPTIM_HandleTypeDef hlcd_lptim;

/**
  * @brief  Initializes TIM MSP.
  * @param  hlptim LPTIM handle
  * @retval None
  */
static void LPTIMx_PWM_MspInit(LPTIM_HandleTypeDef *hlptim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hlptim);

  GPIO_InitTypeDef gpio_init_structure;

  LCD_BL_CTRL_GPIO_CLK_ENABLE();

  /* LPTIMx Peripheral clock enable */
  LCD_LPTIMx_CLK_ENABLE();

  /* Timer channel configuration */
  gpio_init_structure.Mode      = GPIO_MODE_AF_PP;
  gpio_init_structure.Pull      = GPIO_NOPULL;
  gpio_init_structure.Speed     = GPIO_SPEED_FREQ_MEDIUM;
  gpio_init_structure.Alternate = LCD_LPTIMx_CHANNEL_AF;
  gpio_init_structure.Pin       = LCD_BL_CTRL_PIN; /* BL_CTRL */

  HAL_GPIO_Init(LCD_BL_CTRL_GPIO_PORT, &gpio_init_structure);
}

/**
  * @brief  Initializes LPTIM in PWM mode
  * @param  hlptim LPTIM handle
  * @retval None
  */
static void LPTIMx_PWM_Init(LPTIM_HandleTypeDef *hlptim)
{
  LPTIMx_PWM_MspInit(hlptim);

  hlptim->Instance = LCD_LPTIMx;
  (void)HAL_LPTIM_DeInit(hlptim);

  hlptim->Init.CounterSource = LPTIM_COUNTERSOURCE_INTERNAL;
  hlptim->Init.UpdateMode = LPTIM_UPDATE_IMMEDIATE;
  hlptim->Init.Clock.Source = LCD_LPTIMX_CLOCK_SOURCE;
  hlptim->Init.Clock.Prescaler = LCD_LPTIMX_PRESCALER_VALUE;
  hlptim->Init.UltraLowPowerClock.SampleTime = LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION;
  hlptim->Init.Trigger.Source = LPTIM_TRIGSOURCE_SOFTWARE;
  hlptim->Init.Trigger.ActiveEdge = LPTIM_ACTIVEEDGE_RISING;
  hlptim->Init.Trigger.SampleTime = LPTIM_TRIGSAMPLETIME_DIRECTTRANSITION;
  hlptim->Init.Input1Source = LPTIM_INPUT1SOURCE_GPIO;
  hlptim->Init.Input2Source = LPTIM_INPUT2SOURCE_GPIO;
  hlptim->Init.UltraLowPowerClock.Polarity = LPTIM_CLOCKPOLARITY_RISING;
  hlptim->Init.OutputPolarity = LPTIM_OUTPUTPOLARITY_LOW;

  (void)HAL_LPTIM_Init(hlptim);

  (void)HAL_LPTIM_PWM_Start(hlptim, LCD_LPTIMX_PERIOD_VALUE, LCD_LPTIMX_PULSE_VALUE);
}

void LCD_SetBrightness(uint32_t Brightness)
{
    (void)HAL_LPTIM_PWM_Start(&hlcd_lptim, LCD_LPTIMX_PERIOD_VALUE, ((uint32_t)(LCD_LPTIMX_PERIOD_VALUE) * Brightness / 100U));
}

// extern "C" void backlightInit()
// {
//   LPTIMx_PWM_Init(&hlcd_lptim);
// }

bool boardBacklightOn = false;
bool isBacklightEnabled() { return boardBacklightOn; }
void backlightFullOn() { boardBacklightOn = true; }

extern "C" void backlightInit() {
    LPTIMx_PWM_Init(&hlcd_lptim);
}
void backlightEnable(uint8_t dutyCycle) {
    LCD_SetBrightness(dutyCycle);
}

void backlightDisable() {}
