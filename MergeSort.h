#pragma once

#include <vector>

class MergeSort
{
public:
	static void Sort(std::vector<int>* list)
	{
		//Starts the sorting from the beginning of the array to the end of the array.
		SortPiece(list, 0, list->size() - 1);
	}
private:
	static void SortPiece(std::vector<int>* list, int start, int end)
	{
		if (start == end)
			return;

		int middle = (start + end)/2;

		//Sorts the left half.
		SortPiece(list, start, middle);
		//Sorts the right half.
		SortPiece(list, middle + 1, end);

		//Merges the two sorted pieces.
		Merge(list, start, middle, end);
	}

	static void Merge(std::vector<int>* list, int start, int middle, int end)
	{
		if (list->size() == 0)
			return;

		int total = end - start + 1;
		int lcount = middle - start + 1;
		int rcount = end - middle;

		int* left = new int[lcount];
		int* right = new int[rcount];

		//Loads the two sorted pieces into left and right.
		for (int i = 0; i < lcount; i++)
			left[i] = list->at(i + start);
		for (int i = 0; i < rcount; i++)
			right[i] = list->at(i + middle + 1);

		//Merges them into one.
		//Pointer arithmatic is used to walk along the elements of each piece.
		//This means the next element to merge is always at the 0th index.
		for (int i = 0; i < total; i++)
		{
			if (rcount > 0 && lcount > 0)
			{
				if (left[0] > right[0])
				{
					list->at(i + start) = right[0];
					right++;
					rcount--;
				}
				else
				{
					list->at(i + start) = left[0];
					left++;
					lcount--;
				}
			}
			else if (rcount > 0)
			{
				list->at(i + start) = right[0];
				right++;
				rcount--;
			}
			else if (lcount > 0)
			{
				list->at(i + start) = left[0];
				left++;
				rcount--;
			}
		}

		//Resetting pointers to allow them to be deleted.
		left -= (middle - start + 1);
		right -= (end - middle);
		delete left;
		delete right;
	}
};
