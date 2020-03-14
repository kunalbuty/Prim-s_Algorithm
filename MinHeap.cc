#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

MinHeap::MinHeap(int s)
{
	size = 0;
	capacity = s;
	pos = new int[s];
	arr = (struct MinHeapNode**)malloc(capacity*sizeof(struct MinHeapNode*));
}

void MinHeap::heapify(int i) {
	//sorts an array into heap format
	int l = getLeft(i);
	int r = getRight(i);
	int min = i;
	MinHeapNode* temp;
	if(l < size && arr[l]->key < arr[i]->key)
		min = l;
	if(r < size && arr[r]->key < arr[min]->key)
		min = r;
	if(min != i)
	{
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		heapify(min);
	}
}

MinHeapNode* MinHeap::getMin() {		//completed
	if(arr[0]) {
		return arr[0];
	}
	else {
		return NULL;
	}
}

MinHeapNode* MinHeap::extractMin()
{
	//removes first number in array and then calls heapify.
	if(size <= 0)
		return NULL;
	if(size == 1)
	{
		size--;
		return arr[0];
	}
	
	struct MinHeapNode* root = arr[0];
	struct MinHeapNode* last = arr[size-1];
	arr[0] = last;
	pos[root->v] = size-1;
	pos[last->v] = 0;
	size--;
	heapify(0);
	return root;
}
void MinHeap::insert(int v, int val) {
	MinHeapNode* temp;
	//inserts value into heapified array
	if(size == capacity)
	{
		std::cout << "ERROR: Priority Queue full\n";
	}
	else
	{
		//insert new value at end
		size++;
		int i = size-1;
		arr[i]->key = val;
		arr[i]->v = v;

		//Fix violations in min-heap
		while(i != 0 && arr[getParent(i)]->key > arr[i]->key)
		{
			temp = arr[i];
			arr[i] = arr[getParent(i)];
			arr[getParent(i)] = temp;
			i = getParent(i);
		}
	}
}

void MinHeap::keyDecrease(int v, int key) {
	int i = pos[v];
	MinHeapNode* temp;
	arr[i]->key = key;
	while(i && arr[i]->key < arr[i-1/2]->key) {
		pos[arr[i]->v] = (i-1) / 2;
		pos[arr[(i-1)/2]->v] = i;
		temp = arr[i];
		arr[i] = arr[(i-1)/2];
		arr[(i-1)/2] = temp;
		i = (i-1)/2;
	}
}
