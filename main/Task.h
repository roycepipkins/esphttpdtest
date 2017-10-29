/*
 * Task.h
 *
 *  Created on: Sep 27, 2017
 *      Author: Royce
 */

#ifndef MAIN_TASK_H_
#define MAIN_TASK_H_

#include "freertos/task.h"
#include "Runnable.h"

class Task {
public:
	Task();
	virtual ~Task();

	bool Start(
			Runnable* runnable,
			const char* name,
			unsigned short stack_size,
			int32_t core,
			uint8_t priority);
private:
	TaskHandle_t task_handle;
	Runnable* runnable;
	static void TaskEntry(void* vMe);
};

#endif /* MAIN_TASK_H_ */
