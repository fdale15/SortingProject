#include <chrono>
#include <iostream>

using namespace std::chrono;

class Timer
{
private:
	static long start_time;
	static long end_time;
public:
	static void Start()
	{
		start_time = duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
	}

	static long Stop()
	{
		end_time = duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
		return (end_time - start_time);
	}

	static long Time()
	{
		return duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
	}
};

long Timer::start_time = 0;
long Timer::end_time = 0;
