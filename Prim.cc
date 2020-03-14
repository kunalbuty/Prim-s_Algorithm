#include "Prim.h"
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

void MST_Prim(Graph* graph)
{
	int V = graph->getSize();
	int parent[V];
	int key[V];
	int u, v;
	MinHeap Q(V);

	for(int i = 1; i < V; i++)
	{
		parent[i] = -1;
		key[i] = MAX;
		Q.insert(i, key[i]);
		Q.setPos(i);
	}
	key[0] = 0;
	Q.insert(0, key[0]);
	Q.setPos(0);

	Q.setSize(V);

	while(Q.getSize() != 0) {
		struct MinHeapNode* node = Q.extractMin();
		u = node->v;

		for(int i=0;i<graph->getSize();i++) {
			for(int j=0; j < graph->getAListSize(i);j++) {
				v = graph->getDstNode(i,j);
				if((Q.getPos(v) < Q.getSize()) && graph->getWeight(i,j) < key[v]) {
					key[v] = graph->getWeight(i,j);
					parent[v] = u;
					Q.keyDecrease(v, key[v]);
				}
			}
		}
	}
}
