#pragma once

#include <vector>

class MergeSort
{
public:
	static void Sort(std::vector<int>* list, int start, int end)
	{
		if (start == end)
			return;

		int middle = (start + end)/2;

		Sort(list, start, middle);
		Sort(list, middle + 1, end);

		Merge(list, start, middle, end);
	}
private:
	static void Merge(std::vector<int>* list, int start, int middle, int end)
	{
		if (list->size() == 0)
			return;

		int total = end - start + 1;
		int lcount = middle - start + 1;
		int rcount = end - middle;

		int* left = new int[lcount];
		int* right = new int[rcount];

		for (int i = 0; i < lcount; i++)
			left[i] = list->at(i + start);
		for (int i = 0; i < rcount; i++)
			right[i] = list->at(i + middle + 1);

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
