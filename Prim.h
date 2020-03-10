#ifndef PRIM_HEADER
#define PRIM_HEADER

struct heapNode {
	heapNode* leftChild;
	heapNode* rightChild;
	heapNode* parent;
	int value;
}

class Min_Heap {
	public:
		Min_Heap();
		int getMin();
		void extractMin();
		void insert(int value);
	private:
		heapNode* root;
}

#endif