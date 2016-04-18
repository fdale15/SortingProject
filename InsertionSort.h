#include <vector>
#include <iostream>

class InsertionSort 
{
public:
	static void Sort(std::vector<int>* list)
	{	
		for (int i = 0; i < list->size(); i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (list->at(j + 1) < list->at(j))
				{
					int temp = list->at(j);
					list->at(j) = list->at(j + 1);
					list->at(j + 1) = temp;
				}
			}

		}
	}
};