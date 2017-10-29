/*
 * main.cpp
 *
 *  Created on: Aug 11, 2017
 *      Author: Royce
 */

#include "sdkconfig.h"
#include <stdio.h>
#include <fstream>
#include <cstring>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdmmc_defs.h"
#include "sdmmc_cmd.h"

#include "Timer.h"
#include "Timestamp.h"

static const char* TAG = "Animatronito";


extern "C"
{
void app_main();
}

void MountSDCard()
{
	ESP_LOGI(TAG, "Initializing SD card");

	sdmmc_host_t host;
	host.flags = SDMMC_HOST_FLAG_4BIT;
	host.max_freq_khz = 40000;
	host.slot = SDMMC_HOST_SLOT_1;
	host.io_voltage = 3.3f;
	host.init = &sdmmc_host_init;
	host.set_bus_width = &sdmmc_host_set_bus_width;
	host.set_card_clk = &sdmmc_host_set_card_clk;
	host.do_transaction = &sdmmc_host_do_transaction;
	host.deinit = &sdmmc_host_deinit;


	// To use 1-line SD mode, uncomment the following line:
	// host.flags = SDMMC_HOST_FLAG_1BIT;

	// This initializes the slot without card detect (CD) and write protect (WP) signals.
	// Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
	sdmmc_slot_config_t slot_config;
	slot_config.gpio_cd = SDMMC_SLOT_NO_CD;
	slot_config.gpio_wp = SDMMC_SLOT_NO_WP;
	slot_config.width = SDMMC_SLOT_WIDTH_DEFAULT;


	// Options for mounting the filesystem.
	// If format_if_mount_failed is set to true, SD card will be partitioned and formatted
	// in case when mounting fails.
	esp_vfs_fat_sdmmc_mount_config_t mount_config;
	mount_config.format_if_mount_failed = false;
	mount_config.max_files = 5;

	// Use settings defined above to initialize SD card and mount FAT filesystem.
	// Note: esp_vfs_fat_sdmmc_mount is an all-in-one convenience function.
	// Please check its source code and implement error recovery when developing
	// production applications.
	sdmmc_card_t* card;
	esp_err_t ret = esp_vfs_fat_sdmmc_mount("/sdcard", &host, &slot_config, &mount_config, &card);
	if (ret != ESP_OK) {
		if (ret == ESP_FAIL) {
			ESP_LOGE(TAG, "Failed to mount filesystem. If you want the card to be formatted, set format_if_mount_failed = true.");
		} else {
			ESP_LOGE(TAG, "Failed to initialize the card (%d). Make sure SD card lines have pull-up resistors in place.", ret);
		}
		return;
	}

	// Card has been initialized, print its properties
	sdmmc_card_print_info(stdout, card);
}


void app_main()
{
	Timer clock(TIMER_GROUP_0, TIMER_0);
	Timestamp::SetClock(&clock);

	MountSDCard();

}
