#include <vector>
#include <unordered_map>

using namespace std;

class CountingSort
{
public:
  static void Sort(vector<int>* list)
  {
    unordered_map<int, int> map;
    int max = 0, min = 0;
    //Load all numbers into map and find max.
    for (int i = 0; i < list->size(); i++)
    {
      //If number exists in map, increment its count.
      if (map.count(list->at(i)) > 0)
      {
        map[list->at(i)]++;
      }
      //Number is new, set its count to 1 and check for max.
      else
      {
        map[list->at(i)] = 1;

        if (list->at(i) > max)
          max = list->at(i);
        if (list->at(i) < min)
          min = list->at(i);
      }
    }

    //Unload all numbers from map in sequential order.
    for (int i = min, c = 0; i <= max; i++)
    {
      if (map.count(i) > 0)
      {
        for (int j = 0; j < map[i]; j++, c++)
        {
          list->at(c) = i;
        }
      }
    }
  }
};