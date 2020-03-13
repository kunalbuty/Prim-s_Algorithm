#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

MinHeap::MinHeap(int s)
{
	size = 0;
	capacity = s;
	values = new int[s];
}

void MinHeap::heapify(int i) {
	//sorts an array into heap format
	int l = getLeft(i);
	int r = getRight(i);
	int min = i;
	int temp;
	if(l < size && values[l] < values[i])
		min = l;
	if(r < size && values[r] < values[min])
		min = r;
	if(min != i)
	{
		temp = values[i];
		values[i] = values[min];
		values[min] = temp;
		heapify(min);
	}
}

int MinHeap::getMin() {		//completed
	if(values[0]) {
		return values[0];
	}
	else {
		return -1;
	}
}

int MinHeap::extractMin()
{
	//removes first number in array and then calls heapify.
	if(size <= 0)
		return -1;
	if(size == 1)
	{
		size--;
		return values[0];
	}
	
	int root = values[0];
	values[0] = values[size-1];
	size--;
	heapify(0);
	return root;
}
void MinHeap::insert(int val) {
	int temp;
	//inserts value into heapified array
	if(size == capacity)
	{
		std::cout << "ERROR: Priority Queue full\n";
		return;
	}

	//insert new value at end
	size++;
	int i = size-1;
	values[i] = val;

	//Fix violations in min-heap
	while(i != 0 && values[getParent(i)] > values[i])
	{
		temp = values[i];
		values[i] = values[getParent(i)];
		values[getParent(i)] = temp;
		i = getParent(i);
	}
}
