/*
 * Timestamp.h
 *
 *  Created on: Sep 25, 2017
 *      Author: Royce
 */

#ifndef MAIN_TIMESTAMP_H_
#define MAIN_TIMESTAMP_H_
#include "timer.h"

class Timestamp {
public:
	Timestamp();
	virtual ~Timestamp();
	void Update();
	uint64_t Elapsed();

	static void SetClock(Timer* timing_clock);
protected:
	static Timer* clock;
	uint64_t clock_value;
};

#endif /* MAIN_TIMESTAMP_H_ */
