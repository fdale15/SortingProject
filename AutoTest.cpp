#pragma once

#include "AutoTest.h"

using namespace std;

//Initializes the tester with the test data.
AutoTimeTester::AutoTimeTester(vector<int>* data)
{
	this->data = data;
}

AutoTimeTester::~AutoTimeTester()
{
	Tests.clear();
	delete data;
}

//Adds a test to be ran.
void AutoTimeTester::AddTest(string name, void(*_Test)(vector<int>*))
{
	Tests.push_back(Test(name, _Test));
}

//Runs the tests the specified # of times.
void AutoTimeTester::RunTests(int count)
{
	//Iterate count number of times.
	for (int i = 0; i < count; i++)
	{
		//Iterate through all tests.
		for (int j = 0; j < Tests.size(); j++)
		{
			cout << "Running test: " << Tests[j].GetName() << endl;
			//Get a new copy of the unsorted list.
			vector<int>* freshData = new vector<int>(*data);

			//Start the timer.
			Timer::Start();
			//Run the test with the new copy of the list.
			Tests[j].Run(freshData);
			//Stop the timer and add the time it returns to the current tests runtimes.
			Tests[j].AddTime(Timer::Stop());

			//Deallocate the memory used earlier.
			delete freshData;
			//Print the current test result to file.
			FilePrint(Tests[j]);
			//Print the current test result to console.
			ConsolePrint(Tests[j]);
		}
	}
	//Print all test results to file.
	FilePrintAll();
	//Print all test results to console.
	ConsolePrintAll();
}

//Prints out all the test statistics to console.
void AutoTimeTester::ConsolePrintAll()
{
	PrintResults(&cout);
}

//Prints one test statistic to console.
void AutoTimeTester::ConsolePrint(Test test)
{
	test.Print(&cout);
}

//Prints out all the test statistics to file.
void AutoTimeTester::FilePrintAll()
{
	fstream fout("./Results/AllTestResults-" + to_string(Timer::Time()) + ".txt", fstream::out); 
	PrintResults(&fout);
	fout.close();
}

//Prints one test statistic to file.
void AutoTimeTester::FilePrint(Test test)
{
	fstream fout("./Results/" + test.GetName() + "-" + to_string(Timer::Time()) + ".txt", fstream::out); 
	test.Print(&fout);
	fout.close();
}

//Prints out all the test statistics to specified stream.
void AutoTimeTester::PrintResults(ostream* out)
{
	for (int i = 0; i < Tests.size(); i++)
	{
		if (Tests[i].GetCount() > 0)
			Tests[i].Print(out);
	}
}