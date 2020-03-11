#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

Graph::Graph(std::string fileName) {
	//readfile
	int srcNode,dstNode,numNodes,lineLength,wordNum,index1,index2;
	int currentNode;
	int firstLine=1;
	int temp=2;
	AdjacencyList* currentAdjList;
	float weight;
	std::string line;
	std::ifstream myfile (fileName.c_str());
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			if(firstLine==1) {
				firstLine=0;
				numNodes=atoi(line.c_str());
				continue;
			}
			wordNum=0;
			lineLength=line.length();
			for(int i=0;i<lineLength;i++) {
				if(line[i]==' ') {
					if(wordNum==0) {
						wordNum++;
						index1=i+1;
						srcNode=atoi(line.substr(0,i-1).c_str());
					}
					else {
						index2=i+1;
						dstNode=atoi(line.substr(index1,i).c_str());
						weight=atof(line.substr(index2,lineLength-3).c_str());
						break;
					}
				}
			}

			if(srcNode==currentNode) {
				//if still on same node, then add to current alist vector
				currentAdjList->insert(dstNode,weight);
			}
			else {
				//if on new node, create new aList vector and push into aLists
				//also create new node and push into nodes
				AdjacencyList* adjList=new AdjacencyList();
				adjList->insert(dstNode,weight);
				currentAdjList=adjList;
				aLists.push_back(adjList);
				nodes.push_back(srcNode);
			}
			
			/*std::cout<< "source:_" << srcNode << "_dst:_" << dstNode << "weight_"  <<weight << "\n";
			if(temp==0) {
				break;
			}
			else {
				temp--;

			}
			*/
		}
	}
	//read line 1
	/*while reading file*/ {

	}

}