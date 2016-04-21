#pragma once

#include <vector>
#include <ostream>

using namespace std;

//Test for Auto tester
class Test
{
private:
	//Name of the test.
	string Name;

	//The number of times the test has ran.
	int Count;

	//The method to test.
	void(*_Test)(vector<int>*);

	//The collection of durations of time the test took to complete.
	vector<long> RunTimes;

	//Returns the sum of the Run Times.
	long GetSum();
public:
		//Name of the test.

	//Initializes the Test object with a name and method to test.
	Test(string Name, void(*_Test)(vector<int>*));


	//Runs the test with the specified data and increments the count.
	void Run(vector<int>* data);

	//Adds a time to the RunTimes.
	void AddTime(long _time);

	//Prints current test results to the stream provided.
	void Print(ostream* out);

	//Returns the number of times the test has ran.
	int GetCount();

	//Returns the name of the test.
	string GetName();

	//Returns the average of the running times.
	long GetTimeAvg();

};