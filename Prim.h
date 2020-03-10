#ifndef PRIM_HEADER
#define PRIM_HEADER
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class MinHeap {
	public:
		int getMin(int arr[]);
		void heapify(int arr[]);
		void extractMin(int arr[]);
		void insert(int arr[],int val);
	private:
		int size;
		int values[];

};

#endif