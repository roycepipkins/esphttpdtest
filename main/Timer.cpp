/*
 * Timer.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Royce
 */
#include "sdkconfig.h"
#include "Timer.h"
#include "esp_err.h"
#include "esp_log.h"

static const char* TAG = "Timer";
#ifndef CONFIG_LOG_DEFAULT_LEVEL
#define CONFIG_LOG_DEFAULT_LEVEL 0
#endif

Timer::Timer(timer_group_t timer_group, timer_idx_t timer_num) :
	_timer_group(timer_group),
	_timer_num(timer_num)
{
	timer_config_t cfg;
	cfg.alarm_en = false;
	cfg.auto_reload = true; //292M years from now this WILL still be running
	cfg.counter_dir = TIMER_COUNT_UP;
	cfg.divider = 40000;	//makes each tick half a millisecond
	cfg.intr_type = TIMER_INTR_MAX;

	if (ESP_OK != timer_init(_timer_group, _timer_num, &cfg))
	{
		ESP_LOGE(TAG, "Failed to initialize timer.");
	}

	if (ESP_OK != timer_start(_timer_group, _timer_num))
	{
		ESP_LOGE(TAG, "Failed to start timer.");
	}
}

Timer::~Timer()
{
	if (ESP_OK != timer_pause(_timer_group, _timer_num))
	{
		ESP_LOGE(TAG, "Failed to pause timer.");
	}
}

uint64_t Timer::GetTimerTicks()
{
	uint64_t ticks = 0;
	timer_get_counter_value(_timer_group, _timer_num, &ticks);
	return ticks;
}
