#pragma once

#include <vector>
#include "LeonardoHeap.h"

class SmoothSort
{
public:
	static void Sort(vector<int>* list)
	{
		LeonardoHeap lh;
		//Creates a LeonardoHeap
		for (int i = 0; i < list->size(); i++)
		{
			lh.Insert(list->at(i));
		}

		//Pops off the maximum value into the array in reverse order.
		for (int i = list->size() - 1; i >= 0; i--)
		{
			list->at(i) = lh.Dequeue();
		}
	}
};