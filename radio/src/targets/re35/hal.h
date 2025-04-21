/*
 * Copyright (C) EdgeTX
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

#pragma once

#define CPU_FREQ                        480000000
#define PERI1_FREQUENCY                 120000000
#define PERI2_FREQUENCY                 120000000
#define TIMER_MULT_APB1                 2
#define TIMER_MULT_APB2                 2

// Millisecond timer
#define MS_TIMER                        TIM14
#define MS_TIMER_IRQn                   TIM8_TRG_COM_TIM14_IRQn
#define MS_TIMER_IRQHandler             TIM8_TRG_COM_TIM14_IRQHandler

// #define TELEMETRY_EXTI_PRIO             0 // required for soft serial

// Power
#define PWR_ON_GPIO                   GPIO_PIN(GPIOC, 4) // PC.04
#define PWR_SWITCH_GPIO               GPIO_PIN(GPIOC, 5) // PC.05

// QSPI
#define QSPI_CLK_GPIO         GPIO_PIN(GPIOB, 2)  
#define QSPI_CS_GPIO          GPIO_PIN(GPIOG, 6)  
#define QSPI_MISO_GPIO        GPIO_PIN(GPIOF, 9)  
#define QSPI_MOSI_GPIO        GPIO_PIN(GPIOF, 8)  
#define QSPI_WP_GPIO          GPIO_PIN(GPIOF, 7)  
#define QSPI_HOLD_GPIO        GPIO_PIN(GPIOF, 6)  

#define QSPI_CLK_GPIO_AF      GPIO_AF9
#define QSPI_CS_GPIO_AF       GPIO_AF10
#define QSPI_MISO_GPIO_AF     GPIO_AF10
#define QSPI_MOSI_GPIO_AF     GPIO_AF10
#define QSPI_WP_GPIO_AF       GPIO_AF9
#define QSPI_HOLD_GPIO_AF     GPIO_AF9
#define QSPI_FLASH_SIZE       0x1000000

// Keys
#define KEYS_GPIO_REG_ENTER           GPIOI
#define KEYS_GPIO_PIN_ENTER           LL_GPIO_PIN_8  // PI.08
#define KEYS_GPIO_REG_PAGEDN          GPIOD
#define KEYS_GPIO_PIN_PAGEDN          LL_GPIO_PIN_11 // PD.11
#define KEYS_GPIO_REG_MDL             GPIOI
#define KEYS_GPIO_PIN_MDL             LL_GPIO_PIN_6  // PI.06
#define KEYS_GPIO_REG_EXIT            GPIOB
#define KEYS_GPIO_PIN_EXIT            LL_GPIO_PIN_15  // PB.15
#define KEYS_GPIO_REG_SYS             GPIOH
#define KEYS_GPIO_PIN_SYS             LL_GPIO_PIN_12  // PH.12
#define KEYS_GPIO_REG_TELE            GPIOD
#define KEYS_GPIO_PIN_TELE            LL_GPIO_PIN_13  // PD.13

// Rotary Encoder
#define ROTARY_ENCODER_GPIO             GPIOH
#define ROTARY_ENCODER_GPIO_PIN_A       LL_GPIO_PIN_11 // PH.11
#define ROTARY_ENCODER_GPIO_PIN_B       LL_GPIO_PIN_10 // PH.10
#define ROTARY_ENCODER_POSITION()       ((ROTARY_ENCODER_GPIO->IDR >> 10) & 0x03)
#define ROTARY_ENCODER_EXTI_LINE1       LL_EXTI_LINE_11
#define ROTARY_ENCODER_EXTI_LINE2       LL_EXTI_LINE_10
#if !defined(USE_EXTI15_10_IRQ)
  #define USE_EXTI15_10_IRQ
  #define EXTI15_10_IRQ_Priority 5
#endif
#define ROTARY_ENCODER_EXTI_PORT        LL_SYSCFG_EXTI_PORTH
#define ROTARY_ENCODER_EXTI_SYS_LINE1   LL_SYSCFG_EXTI_LINE11
#define ROTARY_ENCODER_EXTI_SYS_LINE2   LL_SYSCFG_EXTI_LINE10
#define ROTARY_ENCODER_TIMER            TIM5
#define ROTARY_ENCODER_TIMER_IRQn       TIM5_IRQn
#define ROTARY_ENCODER_TIMER_IRQHandler TIM5_IRQHandler

#define ROTARY_ENCODER_INVERTED

// Switches
#define STORAGE_SWITCH_A
#define HARDWARE_SWITCH_A
#define SWITCHES_GPIO_REG_A_H           GPIOD
#define SWITCHES_GPIO_PIN_A_H           LL_GPIO_PIN_4  // PD.04
#define SWITCHES_GPIO_REG_A_L           GPIOJ
#define SWITCHES_GPIO_PIN_A_L           LL_GPIO_PIN_14 // PJ.14
#define STORAGE_SWITCH_B
#define HARDWARE_SWITCH_B
#define SWITCHES_GPIO_REG_B_H           GPIOJ
#define SWITCHES_GPIO_PIN_B_H           LL_GPIO_PIN_12 // PJ.12
#define SWITCHES_GPIO_REG_B_L           GPIOA
#define SWITCHES_GPIO_PIN_B_L           LL_GPIO_PIN_15 // PA.15
#define STORAGE_SWITCH_C
#define HARDWARE_SWITCH_C
#define SWITCHES_GPIO_REG_C_H           GPIOH
#define SWITCHES_GPIO_PIN_C_H           LL_GPIO_PIN_15 // PH.15
#define SWITCHES_GPIO_REG_C_L           GPIOH
#define SWITCHES_GPIO_PIN_C_L           LL_GPIO_PIN_14 // PH.14
#define STORAGE_SWITCH_D
#define HARDWARE_SWITCH_D
#define SWITCHES_GPIO_REG_D_H           GPIOA
#define SWITCHES_GPIO_PIN_D_H           LL_GPIO_PIN_8  // PA.08
#define SWITCHES_GPIO_REG_D_L           GPIOH
#define SWITCHES_GPIO_PIN_D_L           LL_GPIO_PIN_13  // PH.13
#define STORAGE_SWITCH_E
#define HARDWARE_SWITCH_E
#define SWITCHES_GPIO_REG_E           GPIOH
#define SWITCHES_GPIO_PIN_E           LL_GPIO_PIN_9  // PH.09
#define STORAGE_SWITCH_F
#define HARDWARE_SWITCH_F
#define SWITCHES_GPIO_REG_F             GPIOB
#define SWITCHES_GPIO_PIN_F             LL_GPIO_PIN_12  // PB.12

#define TRIMS_GPIO_ACTIVE_HIGH
// Trims
#define TRIMS_GPIO_REG_LVD            GPIOJ
#define TRIMS_GPIO_PIN_LVD            LL_GPIO_PIN_8  // PJ.08
#define TRIMS_GPIO_REG_LVU            GPIOG
#define TRIMS_GPIO_PIN_LVU            LL_GPIO_PIN_3  // PG.03
#define TRIMS_GPIO_REG_LHR            GPIOJ
#define TRIMS_GPIO_PIN_LHR            LL_GPIO_PIN_13 // PJ.13
#define TRIMS_GPIO_REG_LHL            GPIOG
#define TRIMS_GPIO_PIN_LHL            LL_GPIO_PIN_2 // PG.02
#define TRIMS_GPIO_REG_RHR            GPIOI
#define TRIMS_GPIO_PIN_RHR            LL_GPIO_PIN_14 // PI.14
#define TRIMS_GPIO_REG_RHL            GPIOI
#define TRIMS_GPIO_PIN_RHL            LL_GPIO_PIN_9 // PI.09
#define TRIMS_GPIO_REG_RVD            GPIOI
#define TRIMS_GPIO_PIN_RVD            LL_GPIO_PIN_11  // PI.11
#define TRIMS_GPIO_REG_RVU            GPIOI
#define TRIMS_GPIO_PIN_RVU            LL_GPIO_PIN_7  // PI.07


// ADC
#define ADC_GPIO_PIN_STICK_LV         LL_GPIO_PIN_0      // PA.00
#define ADC_GPIO_PIN_STICK_RH         LL_GPIO_PIN_1      // PA.01
#define ADC_GPIO_PIN_STICK_RV         LL_GPIO_PIN_2      // PA.02
#define ADC_GPIO_PIN_STICK_LH         LL_GPIO_PIN_3      // PA.03


#define ADC_CHANNEL_STICK_LV          LL_ADC_CHANNEL_16   // ADC1_IN16
#define ADC_CHANNEL_STICK_RH          LL_ADC_CHANNEL_17   // ADC1_IN17
#define ADC_CHANNEL_STICK_RV          LL_ADC_CHANNEL_14   // ADC1_IN14
#define ADC_CHANNEL_STICK_LH          LL_ADC_CHANNEL_15   // ADC1_IN15


#define ADC_GPIO_PIN_SLIDER1          LL_GPIO_PIN_10     // PF.10
#define ADC_GPIO_PIN_SLIDER2          LL_GPIO_PIN_3      // PC.03
#define ADC_GPIO_PIN_BATT             LL_GPIO_PIN_2      // PH.02
#define ADC_GPIO_PIN_EXT1             LL_GPIO_PIN_1      // PC.01  JOYSTICK_LH
#define ADC_GPIO_PIN_EXT2             LL_GPIO_PIN_2      // PC.02  JOYSTICK_LV
#define ADC_GPIO_PIN_EXT3             LL_GPIO_PIN_4      // PH.04  JOYSTICK_RV
#define ADC_GPIO_PIN_EXT4             LL_GPIO_PIN_3      // PH.03  JOYSTICK_RH
#define ADC_GPIOA_PINS                (ADC_GPIO_PIN_STICK_LH | ADC_GPIO_PIN_STICK_LV | ADC_GPIO_PIN_STICK_RH | ADC_GPIO_PIN_STICK_RV)
#define ADC_GPIOF_PINS                (ADC_GPIO_PIN_SLIDER1)
#define ADC_GPIOC_PINS                (ADC_GPIO_PIN_SLIDER2 | ADC_GPIO_PIN_EXT1 | ADC_GPIO_PIN_EXT2)
#define ADC_GPIOH_PINS                (ADC_GPIO_PIN_BATT | ADC_GPIO_PIN_EXT3 | ADC_GPIO_PIN_EXT4)

#define ADC_CHANNEL_BATT              LL_ADC_CHANNEL_13   // ADC3_IN13
#define ADC_CHANNEL_SLIDER1           LL_ADC_CHANNEL_6   // ADC3_IN6
#define ADC_CHANNEL_SLIDER2           LL_ADC_CHANNEL_13  // ADC3_IN13
#define ADC_CHANNEL_EXT1              LL_ADC_CHANNEL_11  // ADC3_IN11 JOYSTICK_LH 
#define ADC_CHANNEL_EXT2              LL_ADC_CHANNEL_12  // ADC3_IN12 JOYSTICK_LV 
#define ADC_CHANNEL_EXT3              LL_ADC_CHANNEL_14  // ADC3_IN14 JOYSTICK_RV 
#define ADC_CHANNEL_EXT4              LL_ADC_CHANNEL_15  // ADC3_IN15 JOYSTICK_RH 
#define ADC_CHANNEL_RTC_BAT           LL_ADC_CHANNEL_VBAT // ADC3_IN18
#define ADC_MAIN                      ADC1
#define ADC_DMA                       DMA2
#define ADC_DMA_CHANNEL               LL_DMAMUX1_REQ_ADC1 
#define ADC_DMA_STREAM                LL_DMA_STREAM_0
#define ADC_DMA_STREAM_IRQ            DMA2_Stream0_IRQn
#define ADC_DMA_STREAM_IRQHandler     DMA2_Stream0_IRQHandler
#define ADC_SAMPTIME                  LL_ADC_SAMPLINGTIME_64CYCLES_5

#define ADC_EXT                       ADC3
#define ADC_EXT_DMA                   DMA2
#define ADC_EXT_CHANNELS              {ADC_CHANNEL_SLIDER1, ADC_CHANNEL_EXT1, ADC_CHANNEL_EXT2, ADC_CHANNEL_EXT3, ADC_CHANNEL_EXT4, ADC_CHANNEL_BATT, ADC_CHANNEL_RTC_BAT}
#define ADC_EXT_DMA_CHANNEL            LL_DMAMUX1_REQ_ADC3
#define ADC_EXT_DMA_STREAM             LL_DMA_STREAM_4
#define ADC_EXT_DMA_STREAM_IRQ         DMA2_Stream4_IRQn
#define ADC_EXT_DMA_STREAM_IRQHandler  DMA2_Stream4_IRQHandler
#define ADC_EXT_SAMPTIME               LL_ADC_SAMPLINGTIME_64CYCLES_5

#define ADC_VREF_PREC2              230

#define ADC_DIRECTION {0,-1,0,-1, /* gimbals */  -1,-1,/* sliders */   0,0,0,0, /* ext1-4 */ 0,	/* vbat */ 0 /* rtc_bat */    }
//*************************************** */

// Led
#define STATUS_LEDS
  #define LED_RED_GPIO                  GPIO_PIN(GPIOG, 10) // PG.10
  #define LED_GREEN_GPIO                GPIO_PIN(GPIOB, 9) // PB.09
  #define LED_BLUE_GPIO                 GPIO_PIN(GPIOE, 3) // PE.03


// Telemetry
// #define TELEMETRY_TX_RX_SWAP
#define TELEMETRY_GPIO                  GPIOD
#define TELEMETRY_TX_GPIO               GPIO_PIN(GPIOD, 5) // PD.05
#define TELEMETRY_RX_GPIO               GPIO_UNDEF //GPIO_PIN(GPIOD, 6) // PD.06
#define TELEMETRY_USART                 USART2
#define TELEMETRY_DMA                   DMA1
#define TELEMETRY_DMA_Stream_TX         LL_DMA_STREAM_6
#define TELEMETRY_DMA_Channel_TX        LL_DMAMUX1_REQ_USART2_TX
#define TELEMETRY_DMA_TX_Stream_IRQ     DMA1_Stream6_IRQn
#define TELEMETRY_DMA_TX_IRQHandler     DMA1_Stream6_IRQHandler
#define TELEMETRY_USART_IRQHandler      USART2_IRQHandler
#define TELEMETRY_USART_IRQn            USART2_IRQn

// TELEMETRY_EXTI IRQ
// #if !defined(USE_EXTI9_5_IRQ)
//   #define USE_EXTI9_5_IRQ
// #endif
// overwrite priority
// #undef EXTI9_5_IRQ_Priority
// #define EXTI9_5_IRQ_Priority            TELEMETRY_EXTI_PRIO

// Software IRQ (Prio 5 -> FreeRTOS compatible)
// #define TELEMETRY_RX_FRAME_EXTI_LINE    LL_EXTI_LINE_4
// #define USE_EXTI4_IRQ
// #define EXTI4_IRQ_Priority 5

// USB
#define USB_GPIO_VBUS                   GPIO_PIN(GPIOA, 9)  // PA.09
#define USB_GPIO_DM                     GPIO_PIN(GPIOA, 11) // PA.11
#define USB_GPIO_DP                     GPIO_PIN(GPIOA, 12) // PA.12
#define USB_GPIO_AF                     GPIO_AF10

// LCD
#define LCD_NRST_GPIO                   GPIOI
#define LCD_NRST_GPIO_PIN               LL_GPIO_PIN_10 // PI.10
#define LCD_SPI_GPIO                    GPIOE
#define LCD_SPI_CS_GPIO_PIN             LL_GPIO_PIN_4  // PE.04
#define LCD_SPI_SCK_GPIO_PIN            LL_GPIO_PIN_2  // PE.02
#define LCD_SPI_MISO_GPIO_PIN           LL_GPIO_PIN_5  // PE.05
#define LCD_SPI_MOSI_GPIO_PIN           LL_GPIO_PIN_6  // PE.06

#define LCD_DC_GPIO                 GPIOG
#define LCD_DC_GPIO_PIN             LL_GPIO_PIN_11  // PG.11
#define LTDC_IRQ_PRIO                   4
#define DMA_SCREEN_IRQ_PRIO             6

// Backlight
// #define BACKLIGHT_TIMER                 TIM8
#define BACKLIGHT_GPIO                  GPIO_PIN(GPIOG, 13) // PG.13 LPTIM1
// #define BACKLIGHT_GPIO_AF               GPIO_AF3
// #define BACKLIGHT_TIMER_FREQ            (PERI2_FREQUENCY * TIMER_MULT_APB2)

// SD
#define SD_SDIO SDMMC1
#define SD_SDIO_TRANSFER_CLK_DIV SDMMC_NSPEED_CLK_DIV

// Uncomment only one line below to select which storage to use
#define STORAGE_USE_SDIO      // Use SD card for storage with SDIO driver
//#define STORAGE_USE_SPI_FLASH // Use SPI flash for storage instead of SD card

// Audio
#define AUDIO_MUTE_GPIO               GPIO_PIN(GPIOA, 7) // PA.07
#define AUDIO_OUTPUT_GPIO             GPIO_PIN(GPIOA, 4) // PA.04
#define AUDIO_DMA_Stream              DMA1_Stream5
#define AUDIO_DMA_Stream_IRQn         DMA1_Stream5_IRQn
#define AUDIO_TIM_IRQn                TIM6_DAC_IRQn
#define AUDIO_TIM_IRQHandler          TIM6_DAC_IRQHandler
#define AUDIO_DMA_Stream_IRQHandler   DMA1_Stream5_IRQHandler
#define AUDIO_TIMER                   TIM6
#define AUDIO_DMA                     DMA1
#define AUDIO_DMA_MUX                 DMAMUX1
#define AUDIO_DMA_DMA_CHANNEL         LL_DMAMUX1_REQ_DAC1_CH1
#define AUDIO_UNMUTE_DELAY            120  // ms
#define AUDIO_MUTE_DELAY              500  // ms

// Touch
#if defined(HARDWARE_TOUCH)
  #define TOUCH_I2C_BUS                   I2C_Bus_1
  #define TOUCH_INT_GPIO                  GPIO_PIN(GPIOB, 4)  // PB.04
  #define TOUCH_RST_GPIO                  GPIO_PIN(GPIOB, 3)  // PB.03

  #define TOUCH_INT_EXTI_Line             LL_EXTI_LINE_4
  #define TOUCH_INT_EXTI_Port             LL_SYSCFG_EXTI_PORTH
  #define TOUCH_INT_EXTI_SysCfgLine       LL_SYSCFG_EXTI_LINE4
  // TOUCH_INT_EXTI IRQ
#if !defined(USE_EXTI4_IRQ)
  #define USE_EXTI4_IRQ
  #define EXTI4_IRQ_Priority  9
#endif
#endif // HARDWARE_TOUCH

// First I2C Bus
#define I2C_B1                      I2C3
#define I2C_B1_SCL_GPIO             GPIO_PIN(GPIOH, 7)  // PH.07
#define I2C_B1_SDA_GPIO             GPIO_PIN(GPIOH, 8)  // PH.08
#define I2C_B1_GPIO_AF              LL_GPIO_AF_4   // I2C3 
#define I2C_B1_CLK_RATE             400000


// Haptic
#define HAPTIC_PWM
// TIM2_CH1
#define HAPTIC_GPIO                   GPIO_PIN(GPIOA, 5) // PA.05
#define HAPTIC_GPIO_TIMER             TIM2
#define HAPTIC_GPIO_AF                GPIO_AF1
#define HAPTIC_TIMER_OUTPUT_ENABLE    TIM_CCER_CC1E | TIM_CCER_CC1P // | TIM_CCER_CC1NE;
#define HAPTIC_TIMER_MODE             TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1PE
#define HAPTIC_TIMER_COMPARE_VALUE    HAPTIC_GPIO_TIMER->CCR1

// Internal PXX1 Module:
//  -> let's assume all internal XJT modules used are either X10 or X12S type
#define EXTERNAL_ANTENNA

#define INTMODULE_PWR_GPIO              GPIO_PIN(GPIOB, 13) // PB.13
#define INTMODULE_TX_GPIO               GPIO_PIN(GPIOB, 11) // PB.11
#define INTMODULE_RX_GPIO               GPIO_PIN(GPIOB, 10) // PB.10
#define INTMODULE_USART                 USART3
#define INTMODULE_USART_IRQn            USART3_IRQn
#define INTMODULE_DMA                   DMA2
#define INTMODULE_DMA_STREAM            LL_DMA_STREAM_7
#define INTMODULE_DMA_STREAM_IRQ        DMA2_Stream7_IRQn
#define INTMODULE_DMA_STREAM_IRQHandler DMA2_Stream7_IRQHandler
#define INTMODULE_DMA_CHANNEL           LL_DMAMUX1_REQ_USART3_TX
#define INTMODULE_RX_DMA                DMA2
#define INTMODULE_RX_DMA_STREAM         LL_DMA_STREAM_2
#define INTMODULE_RX_DMA_CHANNEL        LL_DMAMUX1_REQ_USART3_RX
#define INTMODULE_BOOTCMD_GPIO          GPIO_PIN(GPIOB, 1) // PB.01
#define INTMODULE_BOOTCMD_DEFAULT       0 // RESET


// S.Port update connector
#define SPORT_MAX_BAUDRATE            250000 // < 400000

// External Module
#define EXTMODULE_PWR_GPIO                 GPIO_PIN(GPIOB, 14) // PB.14
#define EXTERNAL_MODULE_PWR_OFF()          gpio_clear(EXTMODULE_PWR_GPIO)

#define EXTMODULE_TX_GPIO                GPIO_PIN(GPIOB, 6) // PB.06
#define EXTMODULE_RX_GPIO                GPIO_PIN(GPIOB, 7) // PB.07
#define EXTMODULE_TIMER_TX_GPIO_AF       GPIO_AF7
#define EXTMODULE_TIMER                  TIM4
#define EXTMODULE_TIMER_Channel          LL_TIM_CHANNEL_CH1
#define EXTMODULE_TIMER_32BITS
#define EXTMODULE_TIMER_FREQ             (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define EXTMODULE_TIMER_IRQn             TIM4_IRQn
#define EXTMODULE_TIMER_IRQHandler       TIM4_IRQHandler
#define EXTMODULE_TIMER_DMA_CHANNEL      LL_DMAMUX1_REQ_TIM4_CH1 //
#define EXTMODULE_TIMER_DMA              DMA1
#define EXTMODULE_TIMER_DMA_STREAM       LL_DMA_STREAM_3
#define EXTMODULE_TIMER_DMA_FLAG_TC      DMA_IT_TCIF1
#define EXTMODULE_TIMER_DMA_STREAM_IRQn  DMA1_Stream3_IRQn
#define EXTMODULE_TIMER_DMA_IRQHandler   DMA1_Stream3_IRQHandler
#define EXTMODULE_USART                  USART1
#define EXTMODULE_USART_IRQn             USART1_IRQn
#define EXTMODULE_USART_IRQHandler       USART1_IRQHandler
#define EXTMODULE_USART_TX_DMA           DMA1
#define EXTMODULE_USART_TX_DMA_CHANNEL   LL_DMAMUX1_REQ_USART1_TX
#define EXTMODULE_USART_TX_DMA_STREAM    LL_DMA_STREAM_4
#define EXTMODULE_USART_RX_DMA_CHANNEL   LL_DMAMUX1_REQ_USART1_RX
#define EXTMODULE_USART_RX_DMA_STREAM    LL_DMA_STREAM_5


// Heartbeat
#define INTMODULE_HEARTBEAT
#define INTMODULE_HEARTBEAT_GPIO                GPIO_PIN(GPIOD, 12) // PD.12 / TIM4_CH1
#define INTMODULE_HEARTBEAT_EXTI_PORT           LL_SYSCFG_EXTI_PORTH
#define INTMODULE_HEARTBEAT_EXTI_SYS_LINE       LL_SYSCFG_EXTI_LINE12
#define INTMODULE_HEARTBEAT_EXTI_LINE           LL_EXTI_LINE_12

// INTMODULE_HEARTBEAT_EXTI IRQ
#if !defined(USE_EXTI15_10_IRQ)
  #define USE_EXTI15_10_IRQ
  #define EXTI15_10_IRQ_Priority 5
#endif
#define INTMODULE_HEARTBEAT_REUSE_INTERRUPT_ROTARY_ENCODER
#if defined(INTERNAL_MODULE_PXX2)
  #define INTMODULE_HEARTBEAT_TRIGGER           GPIO_FALLING
#else
  #define INTMODULE_HEARTBEAT_TRIGGER           GPIO_RISING
#endif

// Trainer Port
#define TRAINER_IN_GPIO                 GPIO_PIN(GPIOC, 6) // PC.06
#define TRAINER_IN_TIMER_Channel        LL_TIM_CHANNEL_CH1
#define TRAINER_OUT_GPIO                GPIO_PIN(GPIOC, 7) // PC.07
#define TRAINER_OUT_TIMER_Channel       LL_TIM_CHANNEL_CH2

#define TRAINER_DETECT_GPIO             GPIO_PIN(GPIOC, 0) // PB.04

#define TRAINER_TIMER                   TIM3
#define TRAINER_TIMER_IRQn              TIM3_IRQn
#define TRAINER_TIMER_IRQHandler        TIM3_IRQHandler
#define TRAINER_GPIO_AF                 GPIO_AF2
#define TRAINER_TIMER_FREQ              (PERI1_FREQUENCY * TIMER_MULT_APB1)

// Trainer CPPM input on heartbeat pin
#define TRAINER_MODULE_CPPM_TIMER            TIM4
#define TRAINER_MODULE_CPPM_FREQ             (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define TRAINER_MODULE_CPPM_GPIO             INTMODULE_HEARTBEAT_GPIO
#define TRAINER_MODULE_CPPM_TIMER_Channel    LL_TIM_CHANNEL_CH1
#define TRAINER_MODULE_CPPM_TIMER_IRQn       TIM4_IRQn
#define TRAINER_MODULE_CPPM_TIMER_IRQHandler TIM4_IRQHandler
#define TRAINER_MODULE_CPPM_GPIO_AF          LL_GPIO_AF_2

// Mixer scheduler timer
#define MIXER_SCHEDULER_TIMER                TIM13
#define MIXER_SCHEDULER_TIMER_FREQ           (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define MIXER_SCHEDULER_TIMER_IRQn           TIM8_UP_TIM13_IRQn
#define MIXER_SCHEDULER_TIMER_IRQHandler     TIM8_UP_TIM13_IRQHandler

// Bluetooth
#define STORAGE_BLUETOOTH
#if defined(BLUETOOTH)
    #define BT_USART                      USART6
    #define BT_USART_IRQn                 USART6_IRQn
    #define BT_USART_GPIO                 GPIOG
    #define BT_TX_GPIO                    GPIO_PIN(GPIOG, 14) // PG.14
    #define BT_RX_GPIO                    GPIO_PIN(GPIOG, 9)  // PG.09
    #define BT_PWR_GPIO                   GPIO_PIN(GPIOD, 7) // PD.07
    #define BT_EN_GPIO                  GPIO_PIN(GPIOD, 3) // PD.03
#endif

// SDRAM
#define SDRAM_BANK2

#define LANDSCAPE_LCD_SML false
#define LANDSCAPE_LCD_STD true
#define LANDSCAPE_LCD_LRG false
#define PORTRAIT_LCD false

#define LCD_W                          480
#define LCD_H                          320
#define LCD_PHYS_H                     LCD_H
#define LCD_PHYS_W                     LCD_W
#define LCD_DEPTH                      16

