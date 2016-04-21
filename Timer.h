#pragma once

#include <chrono>

using namespace std::chrono;

class Timer
{
private:
	static long start_time;
	static long end_time;
public:
	//Starts the timer.
	static void Start();

	//Returns the duration in nanoseconds.
	static long Stop();

	//Returns the current time in nanoseconds.
	static long Time();
};


