option(UNEXPECTED_SHUTDOWN "Enable the Unexpected Shutdown screen" ON)
option(PXX1 "PXX1 protocol support" ON)
option(PXX2 "PXX2 protocol support" OFF)
option(AFHDS3 "AFHDS3 TX Module" OFF)
option(MULTIMODULE "DIY Multiprotocol TX Module (https://github.com/pascallanger/DIY-Multiprotocol-TX-Module)" ON)
option(GHOST "Ghost TX Module" OFF)
option(MODULE_SIZE_STD "Standard size TX Module" ON)
# option(LUA_MIXER "Enable LUA mixer/model scripts support" ON)

set(CPU_TYPE STM32H7)
set(HSE_VALUE 24000000)

set(FLAVOUR h750)
set(TARGET_DIR stm32h750)
set(TARGET_SDRAM_START 0xD0000000)
set(TARGET_SDRAM_SIZE 8M)

set(PWR_BUTTON "PRESS" CACHE STRING "Pwr button type (PRESS/SWITCH)")
set(SDCARD YES)
set(STORAGE_MODELSLIST YES)
set(HAPTIC YES)
set(GUI_DIR colorlcd)
set(BITMAPS_DIR 480x272)
set(RTC_BACKUP_RAM YES)
set(PPM_LIMITS_SYMETRICAL YES)
set(USB_SERIAL ON CACHE BOOL "Enable USB serial (CDC)")
set(HARDWARE_EXTERNAL_MODULE YES)
set(ROTARY_ENCODER YES)
# for size report script
set(CPU_TYPE_FULL STM32H750Ix)
set(TARGET_LINKER_DIR stm32h750_sdram)
# set(TARGET_LINKER_PARAMS "-Wl,--defsym=__PSRAM_START__=0x90000000")
set(SIZE_TARGET_MEM_DEFINE "MEM_SIZE_SDRAM1=8912")
set(FIRMWARE_FORMAT_UF2 YES)

set(BITMAPS_TARGET ${FLAVOUR}_bitmaps)
set(FONTS_TARGET x12_fonts)

set(RADIO_DEPENDENCIES ${RADIO_DEPENDENCIES} ${BITMAPS_TARGET})
set(HARDWARE_TOUCH ON)
# set(FLYSKY_GIMBAL ON)
set(IMU ON)

set(FIRMWARE_QSPI ON)

add_definitions(
  -DSTM32H750xx -DCORE_CM7 -DFIRMWARE_QSPI
  -DSDRAM -DCOLORLCD -DLIBOPENUI -DPCBHORUS -DPCBX10 -DPCBFRSKY -DHARDWARE_KEYS
  -DHARDWARE_TOUCH -DSOFTWARE_KEYBOARD
  -DUSE_USB_FS
)

add_definitions(-DPWR_BUTTON_${PWR_BUTTON})

# Make malloc() thread-safe
add_definitions(-DTHREADSAFE_MALLOC)

set(SDRAM ON)
set(FIRMWARE_STRIP_BOOTLOADER ON)

add_definitions(-DSOFTWARE_VOLUME)
add_definitions(-DAUDIO -DVOICE -DRTCLOCK)
add_definitions(-DSTM32_SUPPORT_32BIT_TIMERS)

# VCP CLI
set(ENABLE_SERIAL_PASSTHROUGH ON CACHE BOOL "Enable serial passthrough")
set(CLI ON CACHE BOOL "Enable CLI")

# if(USE_USB_HS)
#   add_definitions(-DUSE_USB_HS)
# endif()

set(TARGET_SRC_DIR targets/${TARGET_DIR})

set(BOARD_COMMON_SRC
  ${TARGET_SRC_DIR}/board.cpp
  ${TARGET_SRC_DIR}/system_init.cpp
  ${TARGET_SRC_DIR}/lcd_st7796s_driver.cpp
  ${TARGET_SRC_DIR}/backlight_driver.cpp
  ${TARGET_SRC_DIR}/led_driver.cpp
  ${TARGET_SRC_DIR}/haptic_driver.cpp
  # ${TARGET_SRC_DIR}/seesaw.cpp
  # ${TARGET_SRC_DIR}/bsp_io.cpp
  ${TARGET_SRC_DIR}/extflash_driver.cpp
  targets/common/arm/stm32/abnormal_reboot.cpp
  targets/common/arm/stm32/dma2d.cpp
  targets/common/arm/stm32/pwr_driver.cpp
  targets/common/arm/stm32/flash_driver.cpp
  targets/common/arm/stm32/delays_driver.cpp
  targets/common/arm/stm32/rtc_driver.cpp
  targets/common/arm/stm32/watchdog_driver.cpp
  # targets/common/arm/stm32/stm32_xspi_nor.cpp
  targets/common/arm/stm32/stm32_qspi.cpp
  targets/common/arm/stm32/sdram_driver.cpp
  # targets/common/arm/stm32/audio_dac_driver.cpp
  targets/common/arm/stm32/rotary_encoder_driver.cpp
)

# Bootloader board library
add_library(board_bl OBJECT EXCLUDE_FROM_ALL
  ${BOARD_COMMON_SRC}
  ${TARGET_SRC_DIR}/system_clock.cpp
  ${TARGET_SRC_DIR}/extram_driver.cpp
  ${TARGET_SRC_DIR}/bootloader/boot_menu.cpp
)
set(BOOTLOADER_SRC ${BOOTLOADER_SRC} $<TARGET_OBJECTS:board_bl>)

# Firmware board library
add_library(board OBJECT EXCLUDE_FROM_ALL
  ${BOARD_COMMON_SRC}
  ${TARGET_SRC_DIR}/touch_driver.cpp
  # ${TARGET_SRC_DIR}/audio_driver.cpp
  drivers/wm8904.cpp
  targets/common/arm/stm32/lsm6ds_driver.cpp
  targets/common/arm/stm32/mixer_scheduler_driver.cpp
  targets/common/arm/stm32/stm32_switch_driver.cpp
  targets/common/arm/stm32/trainer_driver.cpp
  targets/common/arm/stm32/delays_driver.cpp
  targets/common/arm/stm32/heartbeat_driver.cpp
  targets/common/arm/stm32/module_timer_driver.cpp
  targets/common/arm/stm32/sticks_pwm_driver.cpp
  targets/common/arm/stm32/stm32_pulse_driver.cpp
  targets/common/arm/stm32/stm32_softserial_driver.cpp
  # targets/common/arm/stm32/stm32_i2s.cpp
)
set(FIRMWARE_SRC ${FIRMWARE_SRC} $<TARGET_OBJECTS:board>)

target_sources(board PRIVATE targets/common/arm/stm32/audio_dac_driver.cpp)
# include_directories(${RADIO_SRC_DIR}/fonts/colorlcd gui/${GUI_DIR} gui/${GUI_DIR}/layouts)

if(BOOTLOADER)
  set(FIRMWARE_TARGET_SRC
    ${FIRMWARE_TARGET_SRC}
    ../common/arm/loadboot.cpp
  )
endif()

if(NOT UNEXPECTED_SHUTDOWN)
  add_definitions(-DNO_UNEXPECTED_SHUTDOWN)
endif()

if (MULTIMODULE)
  add_definitions(-DMULTI_PROTOLIST)
endif()

if(NOT INTERNAL_MODULE_PXX1)
  option(ALLOW_TRAINER_MULTI "Allow multimodule to be use as trainer input" OFF)
endif()

if(ALLOW_TRAINER_MULTI)
  add_definitions(-DALLOW_TRAINER_MULTI)
endif()

set(SRC ${SRC}
  io/frsky_firmware_update.cpp
  io/multi_firmware_update.cpp
  io/multi_protolist.cpp
)