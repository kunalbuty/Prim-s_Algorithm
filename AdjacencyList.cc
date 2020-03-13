#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <assert.h>


void AdjacencyList::insert(int vertex, float weight) {
	aListNode* node=new aListNode;
	node->weight=weight;
	node->vertex=vertex;
	//aList.add_to_back();
	aList.push_back(node);
}

aListNode* AdjacencyList::getAdjListVals(int j) {
	return aList.at(j);
}

int AdjacencyList::getSize() {
	return aList.size();
}

