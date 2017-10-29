/*
 * Timestamp.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: Royce
 */

#include "sdkconfig.h"
#include "Timestamp.h"

Timer* Timestamp::clock = nullptr;

Timestamp::Timestamp()
{
	Update();
}

Timestamp::~Timestamp()
{

}

void Timestamp::Update()
{
	clock_value = clock->GetTimerTicks() >> 1; //we'll track in milliseconds
}

uint64_t Timestamp::Elapsed()
{
	return (clock->GetTimerTicks() >> 1) - clock_value;
}

void Timestamp::SetClock(Timer* timing_clock)
{
	clock = timing_clock;
}
