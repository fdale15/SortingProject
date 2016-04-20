#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class CountingSort
{
private:
  static int GetMin(vector<int>* list)
  {
    int result = list->front();
    for (int i = 0; i < list->size(); i++)
    {
      if (list->at(i) < result)
        result = list->at(i);
    }
    return result;
  }

  static int GetMax(vector<int>* list)
  {
    int result = 0;

    return result;
  }
public:
  static void Sort(vector<int>* list)
  {
    int min = list->at(0);
    int max = list->at(0);

    for (int i = 1; i < list->size(); i++)
    {
      if (list->at(i) > max)
        max = list->at(i);
      if (list->at(i) < min)
        min = list->at(i);
    }

    int* count = new int[max - min + 1]();

    for (int i = 0; i < list->size(); i++)
    {
      count[list->at(i) - min]++;
    }

    for (int i = 0, c = 0; i < (max - min + 1); i++)
    {
      for (int j = 0; j < count[i]; j++)
      {
        list->at(c) = i + min;
        c++;
      }
    }

    delete count;
  }
};