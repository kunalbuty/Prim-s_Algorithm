#ifndef PRIM_HEADER
#define PRIM_HEADER
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>

struct MinHeapNode {
	int v;
	int key;
};

class MinHeap {
	public:
		MinHeap(int s);
		void heapify(int i);
		MinHeapNode* getMin();
		MinHeapNode* extractMin();
		void insert(int v, int val);
		void keyDecrease(int v, int key);

		int getParent(int i) {return (i-1)/2; }
		int getLeft(int i) { return (2*i+1); }
		int getRight(int i) { return (2*i+2); }
		int getSize() { return size; }
		int getPos(int p) { return pos[p]; }
		int setPos(int x) { pos[x] = x; }
		int setSize(int s) { size = s; } 
	private:
		int size;
		int capacity;
		int* pos;
		struct MinHeapNode** arr;
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
		int getDstNode(int srcNode,int edgeNum);
		int getNode(int srcNode);
		float getWeight(int srcNode,int edgeNum);
		int getSize();
		int getAListSize(int srcNode);
		
	private:
		int size;
		std::vector<AdjacencyList*> aLists;
		std::vector <int> nodes;
};

void MST_Prim(Graph* g);

#endif
