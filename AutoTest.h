#pragma once

#include <vector>
#include <iostream>
#include "Test.h"
#include "Timer.h"
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

/********************************************************************************/
/*                            AutoTimeTester								    */
/* ____________________________________________________________________________ */
/* This class accepts Test objects and automatically runs them a                */
/* specified number of times. It records the duration of each test              */
/* and prints the results to the console and to a file in the "Results" folder. */
/********************************************************************************/


//1. Init AutoTimeTester with test data.
//2. Add tests to run.
//3. Run tests, specifying # of times to run.
//4. Review Results.

class AutoTimeTester
{
private:
	//Collection of tests to run.
	vector<Test> Tests;
	//Data to run the tests with.
	vector<int>* data;
public:
	//Initializes the tester with the test data.
	AutoTimeTester(vector<int>* data);

	~AutoTimeTester();

	//Adds a test to be ran.
	void AddTest(string name, void(*_Test)(vector<int>*));

	//Runs the tests the specified # of times.
	void RunTests(int count);

	//Prints out all the test statistics to console.
	void ConsolePrintAll();

	//Prints one test statistic to console.
	void ConsolePrint(Test test);

	//Prints out all the test statistics to file.
	void FilePrintAll();

	//Prints one test statistic to file.
	void FilePrint(Test test);

	//Prints out all the test statistics to specified stream.
	void PrintResults(ostream* out);
};