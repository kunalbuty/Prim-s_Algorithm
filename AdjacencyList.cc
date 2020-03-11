#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>




void AdjacencyList::insert(int vertex, float weight) {
	aListNode* node=new aListNode;
	node->weight=weight;
	node->vertex=vertex;
	aList.push_back(node);
}