#pragma once

#include "DataLoader.h"
#include "./InsertionSort.h"
#include "./MergeSort.h"
#include "./HeapSort.h"
#include "./QuickSort.h"
#include "./SmoothSort.h"
#include "./ShellSort.h"
#include "./CountingSort.h"
#include "./AutoTest.h"

int main()
{
	//Init testing class with test data.
	AutoTimeTester tester(DataLoader::GetVector("./dataset.txt", 5000));

	//Add all of the methods to be tested.
	tester.AddTest("Merge Sort", MergeSort::Sort);
	tester.AddTest("Heap Sort", HeapSort::Sort);
	tester.AddTest("Quick Sort", QuickSort::Sort);
	tester.AddTest("Smooth Sort", SmoothSort::Sort);
	tester.AddTest("Shell Sort", ShellSort::Sort);
	tester.AddTest("Counting Sort", CountingSort::Sort);
	tester.AddTest("Insertion Sort", InsertionSort::Sort);

	//Run the test 5 times.
	tester.RunTests(5);

	return 0;
}