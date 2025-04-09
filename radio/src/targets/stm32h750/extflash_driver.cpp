#include "extflash_driver.h"
// #include "stm32_xspi_nor.h"
// #include "stm32h7rsxx_hal_xspi.h"
#include "stm32h7xx_hal_qspi.h"
#include "stm32_qspi.h"
#define QSPI_NOR_PAGE_SIZE 256
extern QSPI_HandleTypeDef hqspi;

#include "stm32_serial_driver.h"

int32_t ExtFLASH_Init()
{
  // init pins
  stm32_qspi_nor_init();

  stm32_qspi_nor_memory_mapped();
  /* Return BSP status */
  return BSP_ERROR_NONE;
}

void ExtFLASH_InitRuntime()
{
  // init HAL hxspi_nur
  // ExtFLASH_InitHALStruct();
  // hxspi_nor.State = HAL_XSPI_STATE_BUSY_MEM_MAPPED;
  // hxspi_nor.Timeout = 5000;
}

//
// ETX HAL flash interface
//

static uint32_t extflash_get_size_kb()
{
  uint32_t size_bytes = QSPI_FLASH_SIZE;
  return size_bytes / 1024;
}

static uint32_t extflash_get_sector(uint32_t address)
{
  address -= QSPI_FLASH_SIZE;
  return address / (64 * 1024);  
}

static uint32_t extflash_get_sector_size(uint32_t sector)
{
  (void)sector;
  return (64 * 1024);
}

static int extflash_erase_sector(uint32_t address)
{
  address -= QSPI_BASE;
  if (stm32_qspi_nor_erase_sector(address) != BSP_ERROR_NONE) {
    return -1;
  }
  return 0;
}

static int extflash_program(uint32_t address, void* data, uint32_t len)
{
  address -= QSPI_BASE;
  while (len > 0) {
    uint32_t size = (len > QSPI_NOR_PAGE_SIZE) ? QSPI_NOR_PAGE_SIZE : len;
    if (stm32_qspi_nor_program(address, data, size) != 0) {
      return -1;
    }
    len -= size;
    address += size;
    data = (uint8_t*)data + size;
  }

  return 0;
}

static int extflash_read(uint32_t address, void* data, uint32_t len)
{
  address -= QSPI_BASE;
  if (stm32_qspi_nor_read(address, data, len) != 0) {
    return -1;
  }

  return 0;
}

const etx_flash_driver_t extflash_driver = {
  .get_size_kb = extflash_get_size_kb,
  .get_sector = extflash_get_sector,
  .get_sector_size = extflash_get_sector_size,
  .erase_sector = extflash_erase_sector,
  .program = extflash_program,
  .read = extflash_read,
};

#if defined(BOOT)
//
// USB DFU interface
//
#include "usbd_dfu.h"

#define MEDIA_DESC_STR "@External Flash   /0x90000000/512*064Kg"

static uint16_t extflash_dfu_init()
{
  return USBD_OK;
}

static uint16_t extflash_dfu_deinit()
{
  return USBD_OK;
}

static uint16_t extflash_dfu_erase(uint32_t address)
{
  if (extflash_erase_sector(address) < 0) {
    return USBD_FAIL;
  }
  return USBD_OK;
}

static uint16_t extflash_dfu_write(uint8_t* src, uint8_t* dest, uint32_t len)
{
  if (extflash_program((intptr_t)dest, (void*)src, len) < 0) {
    return USBD_FAIL;
  }
  return USBD_OK;
}

static uint8_t* extflash_dfu_read(uint8_t* src, uint8_t* dest, uint32_t len)
{
  if (extflash_read((intptr_t)src, (void*)dest, len) < 0) {
    return nullptr;
  }
  return dest;
}

static uint16_t extflash_dfu_get_status(uint32_t address, uint8_t cmd, uint8_t *buffer)
{
  switch (cmd) {
    case DFU_MEDIA_PROGRAM:
      buffer[1] = 1;
      buffer[2] = 0;
      buffer[3] = 0;
      break;

    case DFU_MEDIA_ERASE:
    default:
      buffer[1] = 20;
      buffer[2] = 0;
      buffer[3] = 0;
      break;
  }

  return USBD_OK;
}

const USBD_DFU_MediaTypeDef _extflash_dfu_media = {
  .pStrDesc = (uint8_t*)MEDIA_DESC_STR,
  .Init = extflash_dfu_init,
  .DeInit = extflash_dfu_deinit,
  .Erase = extflash_dfu_erase,
  .Write = extflash_dfu_write,
  .Read = extflash_dfu_read,
  .GetStatus = extflash_dfu_get_status,
};

const void* extflash_dfu_media = &_extflash_dfu_media;

#endif // BOOT
