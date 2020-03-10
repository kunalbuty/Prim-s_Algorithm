#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

void MinHeap::heapify(int arr[]) {
	//sorts an array into heap format
}

int MinHeap::getMin(int arr[]) {		//completed
	if(arr[0]) {
		return arr[0];
	}
	else {
		return -1;
	}
}

void MinHeap::insert(int arr[],int val) {
	//inserts value into heapified array
}

void extractMin(int arr[]) {
	//removes first number in array and then calls heapify.
}