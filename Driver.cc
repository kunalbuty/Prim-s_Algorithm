#include "prim.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char* argv[]) {
	Graph* g=new Graph("input.txt");
	for(int i=0;i<2;i++) {
	//	std::cout << g->getNode(i) << ": ";
		for(int j=0; j < g->getAListSize(i)-1;j++) {
	//		std::cout << g->getDstNode(i,j) <<"," <<  g->getWeight(i,j)  << "\n";
		}
	//	std::cout << "\n\n";
	}
}