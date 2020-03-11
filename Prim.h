#ifndef PRIM_HEADER
#define PRIM_HEADER
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

class MinHeap {
	public:
		int getMin(int arr[]);
		void heapify(int arr[]);
		void extractMin(int arr[]);
		void insert(int arr[],int val);
	private:
		int size;
		int priority;
		int values[];
};

struct aListNode {
	int vertex;
	float weight;
};


class AdjacencyList {
	public:
	void insert(int vertex, float weight);
	private:
		std::vector<aListNode*> aList;
};

class Graph {
	public:
		Graph(std::string fileName);
	private:
		std::vector<AdjacencyList*> aLists;
		std::vector <int> nodes;
};

#endif
