#pragma once

#include "HeapUtils.h"
#include <cmath>

using namespace std;

//Builds a heap from an array.
void HeapUtils::BuildMaxHeap(vector<int>* list, int count)
{
	int i = GetLastParent(count);
	for (; i > 0; i--)
	{
		int maxChildIdx = GetMaxChild(list, count, i);
		Swap(list, count, i, maxChildIdx);
	}
}

//Returns the index of the last node that is not a leaf.
int HeapUtils::GetLastParent(int count)
{
	int levels = log2(count);
	int start = pow(2, levels) - 1;

	for (; start > 0; start--)
	{
		if ((start * 2) + 1 < count)
		{
			break;
		}
	}

	return start;
}

//Returns top number and maintains max-heap.
int HeapUtils::Pop(vector<int>* list, int count)
{
	if (count <= 2)
		return list->at(1);

	int result = list->at(1);

	list->at(1) = list->at(count - 1);
	list->at(count - 1) = -1;

	int maxChild = GetMaxChild(list, count, 1);
	Swap(list, count, 1, maxChild);
	
	return result;
}

//Returns the index of minimum child
int HeapUtils::GetMaxChild(vector<int>* list, int count, int pidx)
{
	if ((2 * pidx) >= count || count <= 2)
		return -1;

	int result = pidx * 2;

	if ((2 * pidx) + 1 < count)
		if (list->at((pidx * 2) + 1) > list->at(result))
			result = (pidx * 2) + 1;

	return result;
}

//Swaps Parent&Child if needed. Recursively swaps children of child.
void HeapUtils::Swap(vector<int>* list, int count, int parentIdx, int childIdx)
{
	if (list->at(parentIdx) < list->at(childIdx))
	{
		int temp = list->at(parentIdx);
		int grandChildIdx = GetMaxChild(list, count, childIdx);

		list->at(parentIdx) = list->at(childIdx);
		list->at(childIdx) = temp;

		if (grandChildIdx > 0)
			Swap(list, count, childIdx, grandChildIdx);
	}
}