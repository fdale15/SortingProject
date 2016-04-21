#pragma once

#include "LeonardoHeap.h"

using namespace std;

//Swaps nodes in a tree to maintain heap.
void LeonardoHeap::HeapSwap(Node* node)
{
	Node* max = GetMaxChild(node);

	if (max != nullptr)
	{
		if (max->data > node->data)
		{
			int temp = max->data;
			max->data = node->data;
			node->data = temp;

			HeapSwap(max);
		}
	}
}

//Makes sure all heaps are heaps.
void LeonardoHeap::HeapSwapAll()
{
	for (int i = 0; i < roots.size(); i++)
	{
		HeapSwap(roots[i]);
	}
}

//Returns a pointer to the max child of a certain node.
Node* LeonardoHeap::GetMaxChild(Node* node)
{
	if (node == nullptr)
		return nullptr;
	if (node->left == nullptr)
		return node->right;
	if (node->right == nullptr)
		return node->left;

	return node->left->data > node->right->data ? node->left : node->right;
}

//Sorts the root nodes.
void LeonardoHeap::SortRoot()
{
	for (int i = 0; i < roots.size() - 1; i++)
	{
		for (int j = i + 1; j < roots.size(); j++)
		{
			if (roots[i]->data > roots[j]->data)
			{
				int temp = roots[i]->data;
				roots[i]->data = roots[j]->data;
				roots[j]->data = temp;
			}
		}
	}
}

//Sorts the root nodes until a certain point.
void LeonardoHeap::Sort(int idx)
{
	for (int i = 0; i < idx; i++)
	{
		for (int j = i + 1; j < idx; j++)
		{
			if (roots[i]->data > roots[j]->data)
			{
				int temp = roots[i]->data;
				roots[i]->data = roots[j]->data;
				roots[j]->data = temp;
			}
		}
	}
}

//Inserts an item into the heap.
void LeonardoHeap::Insert(int value)
{
	Node* node = new Node();
	node->data = value;

	if (roots.size() == 0)
	{
		node->order = 1;
		roots.push_back(node);
		return;
	}

	int idx = roots.size() - 1;
	int prevIdx = idx - 1;

	if (prevIdx > -1)
	{
		//If the last two heaps are of sequential order then combine to make a new heap.
		if (roots[idx]->order + 1 == roots[prevIdx]->order)
		{

			node->right = roots[idx];
			node->left = roots[prevIdx];
			node->order = roots[prevIdx]->order + 1;

			//Add node to leo[n - 2] spot
			roots[prevIdx] = node;

			//Delete node from leo[n - 1] spot
			roots[idx] = nullptr;
			roots.pop_back();

			//Make sure it satisfies heap.
			HeapSwap(roots[idx - 1]);
			SortRoot();
			return;
		}
	}

	if (roots[roots.size() - 1]->order != 1)
		node->order = 1;
	roots.push_back(node);

	SortRoot();
}

//Dequeues the max element and maintains LeonardoHeap.
int LeonardoHeap::Dequeue()
{
	Node* max = roots.back();
	roots.pop_back();
	//Remove topmost node of rightmost heap.
	int result = max->data;


	//If no children, done.
	if (max->left || max->right)
	{
		//Else
		//Fix left of the two heaps.
		if (max->left)
		{
			roots.push_back(max->left);
			SortRoot();
			HeapSwapAll();
		}
		//Fix right of the two heaps.
		if (max->right)
		{
			roots.push_back(max->right);
			SortRoot();
			HeapSwapAll();
		}
	}

	return result;
}