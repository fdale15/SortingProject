#include <iostream>
#include <vector>
#include "DataLoader.h"
#include "./InsertionSort.h"
#include "./MergeSort.h"
#include "./HeapSort.h"
#include "./QuickSort.h"
#include "./SmoothSort.h"
#include "./ShellSort.h"
#include "./CountingSort.h"
#include "./AutoTest.h"

using namespace std;

void Print(vector<int>* list);

int main()
{
	AutoTimeTester tester(DataLoader::GetVector("./dataset.txt", 500000));

	//Perform Merge Sort.
	tester.AddTest("Merge Sort", MergeSort::Sort);

	//Perform Heap Sort.
	tester.AddTest("Heap Sort", HeapSort::Sort);

	//Perform Quick Sort
	tester.AddTest("Quick Sort", QuickSort::Sort);

	tester.AddTest("Smooth Sort", SmoothSort::Sort);

	tester.AddTest("Shell Sort", ShellSort::Sort);

	tester.AddTest("Counting Sort", CountingSort::Sort);

	//Perform Insertion Sort.
	tester.AddTest("Insertion Sort", InsertionSort::Sort);

	tester.RunTests(5);

	return 0;
}

void Print(vector<int>* list)
{
	for (int i = 0; i < list->size(); i++)
	{
		cout << list->at(i) << " ";
	}
	cout << endl;
}
