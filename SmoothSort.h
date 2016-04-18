#include <vector>
#include "LeonardoHeap.h"

class SmoothSort
{
public:
	static void Sort(vector<int>* list)
	{
		LeonardoHeap lh;
		for (int i = 0; i < list->size(); i++)
		{
			lh.Insert(list->at(i));
		}

		for (int i = list->size() - 1; i >= 0; i--)
		{
			list->at(i) = lh.Dequeue();
		}
	}
};