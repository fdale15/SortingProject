#include <iostream>
#include <vector>
#include "DataLoader.h"
#include "./InsertionSort.h"
#include "./MergeSort.h"
#include "./HeapSort.h"
#include "./QuickSort.h"
#include "./SmoothSort.h"
#include "./Timer.h"
#include "./ShellSort.h"
#include "./CountingSort.h"

using namespace std;

void Print(vector<int>* list);
void InsertionSort(vector<int>* list);
void MergeSort(vector<int>* list);
void HeapSort(vector<int>* list);
void QuickSort(vector<int>* list);
void SmoothSort(vector<int>* list);
void ShellSort(vector<int>* list);
void CountingSort(vector<int>* list);

int main()
{
	vector<int>* originalData = DataLoader::GetVector("./dataset.txt", 500000);
	
	//Perform Insertion Sort.
	//InsertionSort(originalData);

	cout << endl;

	//Perform Merge Sort.
	MergeSort(originalData);

	cout << endl;

	//Perform Heap Sort.
	HeapSort(originalData);

	cout << endl;

	//Perform Quick Sort
	QuickSort(originalData);

	cout << endl;

	SmoothSort(originalData);

	cout << endl;

	//ShellSort(originalData);

	cout << endl;

	CountingSort(originalData);

	cout << endl;

	return 0;
}

void InsertionSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Insertion Sort:" << endl;
	//Print(data);

	Timer::Start();
	InsertionSort::Sort(data);
	long timeDiff = Timer::Stop();

	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void MergeSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Merge Sort:" << endl;
	//Print(data);
	Timer::Start();
	MergeSort::Sort(data, 0, data->size() - 1);
	long timeDiff = Timer::Stop();
	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void HeapSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Heap Sort:" << endl;
	//Print(data);
	Timer::Start();
	HeapSort::Sort(data);
	long timeDiff = Timer::Stop();
	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void QuickSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Quick Sort:" << endl;
	//Print(data);
	Timer::Start();
	QuickSort::Sort(data);
	long timeDiff = Timer::Stop();
	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void SmoothSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Smooth Sort:" << endl;
	//Print(data);
	Timer::Start();
	SmoothSort::Sort(data);
	long timeDiff = Timer::Stop();
	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void ShellSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Shell Sort:" << endl;
	//Print(data);
	Timer::Start();
	ShellSort::Sort(data);
	long timeDiff = Timer::Stop();
	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void CountingSort(vector<int>* list)
{
	vector<int>* data = new vector<int>(*list);
	cout << "Counting Sort:" << endl;
	//Print(data);
	Timer::Start();
	CountingSort::Sort(data);
	long timeDiff = Timer::Stop();
	//Print(data);
	cout << "Time (ms): " << timeDiff << endl;
	delete data;
}

void Print(vector<int>* list)
{
	cout << "[";
	for (int i = 0; i < list->size(); i++)
		cout << list->at(i) << ((i + 1 < list->size()) ? ", " : "]");
	cout << endl;
}