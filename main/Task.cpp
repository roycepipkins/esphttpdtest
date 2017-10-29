/*
 * Task.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Royce
 */
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "Task.h"
#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"

Task::Task() {
	// TODO Auto-generated constructor stub

}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

bool Task::Start(
			Runnable* runnable,
			const char* name,
			unsigned short stack_size,
			int32_t core,
			uint8_t priority)
{
	if (!runnable) return false;
	this->runnable = runnable;
	return pdPASS == xTaskCreatePinnedToCore(
			TaskEntry,
			name,
			stack_size,
			this,
			priority,
			&task_handle,
			core);
}

void Task::TaskEntry(void* vMe)
{
	((Task*)vMe)->runnable->run((Task*)vMe);
	vTaskDelete(((Task*)vMe)->task_handle);
}
