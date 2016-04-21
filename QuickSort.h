#pragma once

#include <vector>

using namespace std;

//Not exactly like the one shown in class.
//This quicksort sorts starting from one side only.
class QuickSort 
{
private:
	static void SortPiece(vector<int>* list, int pivot, int end)
	{
	    if(pivot < end)
	    {
	        int pivotLocation = GetPivotLocation(list, pivot, end);
	        //Sorts the left side.
	        SortPiece(list, pivot, pivotLocation);  
	        //Sorts the right side.
	        SortPiece(list, pivotLocation + 1, end);
	    }
	}



	//Gets the correct location for the pivot.
	static int GetPivotLocation(vector<int>* list, int pivot, int end)
	{
	    int pivotValue = list->at(pivot);
	    int left = pivot;
	    int right = pivot + 1;

	    //Starts from right and searched for value less than pivot.
	    //When lesser value is found, left is incremented and swapped with the right value.
	    for(; right < end; right++)
	    {
	        if(list->at(right) <= pivotValue)
	        {
	            left++;
	            swap(list->at(left), list->at(right));
	        }
	    }

	    //When right is at the end, the left value is the correct location for the pivot.
	    //left is always less than pivot, pivot is always left of left so it works out.
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