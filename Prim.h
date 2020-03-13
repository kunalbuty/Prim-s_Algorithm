#ifndef PRIM_HEADER
#define PRIM_HEADER
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

class MinHeap {
	public:
		MinHeap(int s);
		void heapify(int i);
		int getMin();
		int extractMin();
		void insert(int val);
		
		int getParent(int i) {return (i-1)/2; }
		int getLeft(int i) { return (2*i+1); }
		int getRight(int i) { return (2*i+2); }
	private:
		int size;
		int capacity;
		int *values;
};

struct aListNode {
	int vertex;
	float weight;
};


class AdjacencyList {
	public:
		void insert(int vertex, float weight);
		int getSize();
		aListNode* getAdjListVals(int j);
		int size;

		
	private:
		std::vector<aListNode*> aList;


};

class Graph {
	public:
		Graph(std::string fileName);
		int getDstNode(int i,int j);
		int getNode(int i);
		float getWeight(int i,int j);
		int getSize();
		int getAListSize(int i);
		
	private:
		int size;
		std::vector<AdjacencyList*> aLists;
		std::vector <int> nodes;
};

#endif
