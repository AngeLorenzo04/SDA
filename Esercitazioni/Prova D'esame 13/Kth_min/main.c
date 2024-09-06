#include "minheap.h"

extern ElemType KthLeast(const Heap* h, int k);

int main(void) {

	Heap* h = HeapCreateEmpty();

	const ElemType elem[] = {1,3,5,6,10,9};

	for (size_t i = 0; i < 6; i++) {
		
		HeapMinInsertNode(h, elem + i);
	}

	HeapWriteStdout(h);

	KthLeast(h, 2);


	return 0;
}

/*

		5          VETT : 5,3,3,2,1
	   / \             
      3   3          
     / \             
    2   1         
	 
*/