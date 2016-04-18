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
		start_time = duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count();
	}

	static long Stop()
	{
		end_time = duration_cast<microseconds>(steady_clock::now().time_since_epoch()).count();
		return (end_time - start_time);
	}
};

long Timer::start_time = 0;
long Timer::end_time = 0;
