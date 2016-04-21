#pragma once

#include <vector>

using namespace std;

//Contains functions for manipulating array-based heaps.
class HeapUtils
{
public:
	//Builds a heap from an array.
	static void BuildMaxHeap(vector<int>* list, int count);
	//Returns top number and maintains max-heap.
	static int Pop(vector<int>* list, int count);
private:
	//Returns the index of the last node that is not a leaf.
	static int GetLastParent(int count);
	//Returns the index of the maximum child of specified parent index.
	static int GetMaxChild(vector<int>* list, int count, int pidx);
	//Swaps the Parent & Child recursively to maintain heap requirements.
	static void Swap(vector<int>* list, int count, int parentIdx, int childIdx);
};