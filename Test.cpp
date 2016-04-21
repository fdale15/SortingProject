#pragma once

#include "Test.h"

using namespace std;

//Initializes the Test object with a name and method to test.
Test::Test(string Name, void(*_Test)(vector<int>*))
{
	this->Name = Name;
	this->_Test = _Test;
	Count = 0;
}

//Runs the test with the specified data and increments the count.
void Test::Run(vector<int>* data)
{
	_Test(data);
	Count++;
}

//Adds a time to the RunTimes.
void Test::AddTime(long _time)
{
	RunTimes.push_back(_time);
}

//Prints current test results to the stream provided.
void Test::Print(ostream* out)
{
	(*out) << Name << endl;
	(*out) << "Run Times: " << Count << endl;
	(*out) << "Avg Time: " << (float)GetTimeAvg()/1000000000.0f << " sec" << endl << endl;
}

//Returns the number of times the test has ran.
int Test::GetCount()
{
	return Count;
}

//Returns the name of the test.
string Test::GetName()
{
	return Name;
}

//Returns the average of the running times.
long Test::GetTimeAvg()
{
	return GetSum() / RunTimes.size();
}

//Returns the sum of the Run Times.
long Test::GetSum()
{
	long result = 0;

	for (vector<long>::iterator it = RunTimes.begin(); it != RunTimes.end(); ++it)
	{
		result += (*it);
	}

	return result;
}