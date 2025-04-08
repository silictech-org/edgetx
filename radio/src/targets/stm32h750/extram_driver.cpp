#include "extram_driver.h"
#include "stm32_hal_ll.h"
#include "delays_driver.h"

#include "stm32_hal.h"


extern "C" void SDRAM_Init();

int32_t ExtRAM_Init()
{
  SDRAM_Init();
  return BSP_ERROR_NONE;
}

