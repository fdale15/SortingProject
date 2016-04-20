#include <vector>
#include <iostream>
#include "Timer.h"
#include <fstream>
#include <string>

using namespace std;

//Test for Auto tester
class Test
{
private:
	//Name of the test
	string Name;
	//Times tested.
	int Count;
	//Instructions defining what the test does.
	void(*_Test)(vector<int>*);

	vector<long> RunTimes;

	long Sum()
	{
		long result = 0;

		for (vector<long>::iterator it = RunTimes.begin(); it != RunTimes.end(); ++it)
		{
			result += (*it);
		}

		return result;
	}
public:
		//Name of the test.

	Test(string Name, void(*_Test)(vector<int>*))
	{
		this->Name = Name;
		this->_Test = _Test;
		Count = 0;
	}

	//Used to add a running time to a test.
	void AddTime(long _time)
	{
		RunTimes.push_back(_time);
	}

	//Returns the average of the running times.
	long GetTimeAvg()
	{
		return Sum() / RunTimes.size();
	}

	void Print(ostream* out)
	{
		(*out) << Name << endl;
		(*out) << "RunTimes: " << Count << endl;
		(*out) << "Avg Time: " << (float)GetTimeAvg()/1000000000.0f << " sec" << endl << endl;
	}

	int GetCount()
	{
		return Count;
	}

	string GetName()
	{
		return Name;
	}

	void Run(vector<int>* data)
	{
		_Test(data);
		Count++;
	}
};


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
	AutoTimeTester(vector<int>* data)
	{
		this->data = data;
	}

	~AutoTimeTester()
	{
		Tests.clear();
		delete data;
	}

	//Adds a test to be ran.
	void AddTest(string name, void(*_Test)(vector<int>*))
	{
		Tests.push_back(Test(name, _Test));
	}

	//Runs the tests the specified # of times.
	void RunTests(int count)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < Tests.size(); j++)
			{
				cout << "Running test: " << Tests[j].GetName() << endl;
				vector<int>* freshData = new vector<int>(*data);
				Timer::Start();
				Tests[j].Run(freshData);
				Tests[j].AddTime(Timer::Stop());
				delete freshData;
				FilePrint(Tests[j]);
				ConsolePrint(Tests[j]);
			}
		}
		FilePrintAll();
		ConsolePrintAll();
	}

	//Prints out all the test statistics to console.
	void ConsolePrintAll()
	{
		PrintResults(&cout);
	}

	//Prints one test statistic to console.
	void ConsolePrint(Test test)
	{
		test.Print(&cout);
	}

	//Prints out all the test statistics to file.
	void FilePrintAll()
	{
		ofstream fout("./Results/AllTestResults-" + to_string(Timer::Time()) + ".txt");
		PrintResults(&fout);
		fout.close();
	}

	//Prints one test statistic to file.
	void FilePrint(Test test)
	{
		fstream fout("./Results/" + test.GetName() + "-" + to_string(Timer::Time()) + ".txt", fstream::out);
		test.Print(&fout);
		fout.close();
	}


	//Prints out all the test statistics.
	void PrintResults(ostream* out)
	{
		for (int i = 0; i < Tests.size(); i++)
		{
			if (Tests[i].GetCount() > 0)
				Tests[i].Print(out);
		}
	}
};