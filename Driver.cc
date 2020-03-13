#include "prim.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]) {
	Graph* g=new Graph("input.txt");
	
	/*
	//NOTE! Graph works fine, but this print function below doesnt print for nodes with only one dstNode/edge
	for(int i=0;i<g->getSize();i++) {
		std::cout << g->getNode(i) << ": ";
		if(g->getAListSize(i)>1) {
			for(int j=0; j < g->getAListSize(i);j++) {
				std::cout << g->getDstNode(i,j) <<"," <<  g->getWeight(i,j)  << "\n";
			}
		}
		std::cout << "\n\n";
	}
	*/

}