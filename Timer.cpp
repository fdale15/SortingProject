#pragma once

#include "Timer.h"

long Timer::start_time = 0;
long Timer::end_time = 0;

//Starts the Timer.
void Timer::Start()
{
	start_time = duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
}

//Returns the duration in nanoseconds.
long Timer::Stop()
{
	end_time = duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
	return (end_time - start_time);
}

//Returns the current time in nanoseconds.
long Timer::Time()
{
	return duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
}