#include "Prim.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <assert.h>

Graph::Graph(std::string fileName) {
	//readfile
	int srcNode,dstNode,lineLength,wordNum,index1,index2;
	int currentNode=-1;
	int firstLine=1;
	//int temp=25;
	AdjacencyList* adjList;
	AdjacencyList* currentAdjList;
	float weight;
	std::string line;
	std::ifstream myfile (fileName.c_str());
	if(myfile.is_open()) {
		while(getline(myfile,line)) {
			//read all lines
			if(firstLine==1) {
				firstLine=0;
				size=atoi(line.c_str());
				//std::cout << numNodes << "\n";
				continue;
			}
			if(line=="") {
				continue;
			}
			wordNum=0;
			lineLength=line.length();
			for(int i=0;i<lineLength;i++) {
				//for loop parses each line
				if(line[i]==' ') {
					if(wordNum==0) {
						wordNum++;
						index1=i+1;
						srcNode=atoi(line.substr(0,i).c_str());
					}
					else {
						index2=i+1;
						dstNode=atoi(line.substr(index1,i).c_str());
						weight=atof(line.substr(index2,lineLength-3).c_str());
						break;
					}
				}
			}

			//std::cout<< "source: " << srcNode << " dst: " << dstNode << " weight: "  <<weight << "\n";

			
			if(srcNode==currentNode) {
				//if still on same node, then add to current alist vector
				if(currentAdjList) {
					currentAdjList->insert(dstNode,weight);
					currentAdjList->size++;
					//std::cout <<"went here instead";// currentNode;
				}
			}
			else {
				//std::cout << "made it here\n";
				//if on new node, create new aList vector and push into aLists
				//also create new node and push into nodes
				adjList=new AdjacencyList();
				adjList->insert(dstNode,weight);
				aLists.push_back(adjList);
				nodes.push_back(srcNode);

				currentAdjList=adjList;
				currentNode=srcNode;
				currentAdjList->size=1;
			}
			/*if(temp==0) {
				break;
			}
			else {
				temp--;

			}*/
		}
	}
	myfile.close(); 
}

int Graph::getDstNode(int srcNode,int edgeNum) {
	return aLists.at(srcNode)->getAdjListVals(edgeNum)->vertex;
}

float Graph::getWeight(int srcNode,int edgeNum) {
	return aLists.at(srcNode)->getAdjListVals(edgeNum)->weight;
}

int Graph::getNode(int srcNode) {
	return nodes.at(srcNode);
}

int Graph::getSize() {
	return nodes.size();
}

int Graph::getAListSize(int srcNode) {
	//assert(aLists.at(i)->getSize());
	return aLists.at(srcNode)->getSize();
}
