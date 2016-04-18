#include <vector>
#include <iostream>
#include "HeapUtils.h"

using namespace std;

class HeapSort
{
public:
	static void Sort(std::vector<int>* list)
	{
		//Add empty element to beginning to make buildheap work.
		list->insert(list->begin(), -1);

		int count = list->size();

		HeapUtils::BuildMaxHeap(list, count);
		count--;
		for (; count > 0; count--)
		{
			int temp = HeapUtils::Pop(list, count + 1);
			list->at(count) = temp;
		}

		//Remove empty element at beginning to return only values provided originally.
		list->erase(list->begin());
	}
};