#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class DataLoader 
{
public:
	static vector<int>* GetVector(string filename, int n)
	{
		vector<int>* result = new vector<int>();
		fstream file(filename, fstream::in);
		int count = 0;

		while (!file.eof())
		{
			char buff[256];
			file.getline(buff, 256);
			result->push_back(std::stoi(buff));
			count++;
			if (count >= n)
				break;
		}

		cout << "Data Count: " << count << endl;
		return result;
	}
};