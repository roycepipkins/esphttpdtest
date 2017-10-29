/*
 * Timer.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Royce
 */

#ifndef MAIN_TIMER_H_
#define MAIN_TIMER_H_


#include "driver/timer.h"

class Timer {
public:
	Timer(timer_group_t timer_group, timer_idx_t timer_num);
	virtual ~Timer();

	uint64_t GetTimerTicks();
protected:
	timer_group_t _timer_group;
	timer_idx_t _timer_num;
};

#endif /* MAIN_TIMER_H_ */
