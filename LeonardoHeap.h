#pragma once

#include <vector>

using namespace std;

class Node
{
public:
	Node()
	{
		order = 0;
		left = nullptr;
		right = nullptr;
	}

	Node(int value)
	{
		order = 0;
		left = nullptr;
		right = nullptr;
		data = value;
	}

	int data;
	int order;

	Node* left;
	Node* right;
};

class LeonardoHeap
{
	vector<Node*> roots;

	//Swaps nodes in a tree to maintain heap.
	void HeapSwap(Node* node);

	//Makes sure all heaps are heaps.
	void HeapSwapAll();

	//Returns a pointer to the max child of a certain node.
	Node* GetMaxChild(Node* node);

	//Sorts the root nodes.
	void SortRoot();

	//Sorts the root nodes until a certain point.
	void Sort(int idx);
public:
	LeonardoHeap()
	{

	}

	//Inserts an element into the heap.
	void Insert(int value);

	//Dequeues the max element and maintains LeonardoHeap.
	int Dequeue();
};