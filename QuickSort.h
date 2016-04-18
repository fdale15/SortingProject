#pragma once

#include <vector>
#include <iostream>

using namespace std;

class QuickSort 
{
private:
	static void SortPiece(vector<int>* list, int pivot, int end)
	{
	    int pivotLocation;

	    if(pivot < end)
	    {
	        pivotLocation = GetPivotLocation(list, pivot, end);
	        SortPiece(list, pivot, pivotLocation);  
	        SortPiece(list, pivotLocation + 1, end);
	    }
	}

	//Not exactly like the one shown in class.
	//This quicksort sorts starting from one side only.
	static int GetPivotLocation(vector<int>* list, int pivot, int end)
	{
	    int pivotValue = list->at(pivot);
	    int left = pivot;
	    int right = pivot + 1;

	    for(; right < end; right++)
	    {
	        if(list->at(right) <= pivotValue)
	        {
	            left++;
	            swap(list->at(left), list->at(right));
	        }

	    }

	    //I didn't know STL had a function for this.
	    swap(list->at(left), list->at(pivot));

	    return left;
	}
public:
	static void Sort(vector<int>* list)
	{
		//Sort the array piece from index 0 to n-1.
		SortPiece(list, 0, list->size() - 1);
	}
};