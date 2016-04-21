#pragma once

#include <vector>

class ShellSort 
{
public:
	static void Sort(std::vector<int>* list)
	{
     int flag = 1;
     int h = list->size();

     while (flag || (h > 1))      // boolean flag (true when not equal to 0)
     {
        flag = 0; // reset flag to 0 to check for future swaps
        h = (h+1) / 2;  //get next count of values in between.
        
        for (int i = 0; i < (list->size() - h); i++)
        {
              if (list->at(h + i) < list->at(i))
              {
                      int temp = list->at(h + i);      // swap positions i+h and i
                      list->at(h + i) = list->at(i);
                      list->at(i) = temp;
                      flag = 1; 
              }
        }
     }
	}
};
