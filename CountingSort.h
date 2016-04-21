#pragma once

#include <vector>

using namespace std;

class CountingSort
{
public:
  static void Sort(vector<int>* list)
  {
    //Gets the min and max.
    int min = list->at(0);
    int max = list->at(0);

    for (int i = 1; i < list->size(); i++)
    {
      if (list->at(i) > max)
        max = list->at(i);
      if (list->at(i) < min)
        min = list->at(i);
    }

    //Creates a new array based on the range of min and max.
    int range = max - min + 1;
    int* count = new int[range]();

    //Increments count of all numbers present.
    for (int i = 0; i < list->size(); i++)
    {
      //The min is the offset.
      //This is to reduce the wasted space that occurs before the minimum value in the count array.
      count[list->at(i) - min]++;
    }

    //Outputs the count in numerical order.
    for (int i = 0, c = 0; i < range; i++)
    {
      for (int j = 0; j < count[i]; j++)
      {
        //The min is the offset.
        list->at(c) = i + min;
        c++;
      }
    }

    delete count;
  }
};