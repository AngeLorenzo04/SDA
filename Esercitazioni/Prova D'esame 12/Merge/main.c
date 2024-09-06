#include "minheap.h"
extern Heap* MergeHeap(const Heap* h1, const Heap* h2);
int main(void) {

	Heap* h1 = HeapCreateEmpty();
	Heap* h2 = HeapCreateEmpty();

	const ElemType elem1[] = {32,5,4,6,12,23};
	const ElemType elem2[] = {2,5,22,3,7,33};

	for (size_t i = 0; i < 6; i++) {
		
		HeapMinInsertNode(h1, elem1 + i);
	}
	for (size_t i = 0; i < 6; i++) {

		HeapMinInsertNode(h2, elem2 + i);
	}

	printf("Heap1: \n");
	HeapWriteStdout(h1);

	printf("Heap2: \n");
	HeapWriteStdout(h2);

	
	HeapWriteStdout(MergeHeap(h1, h2));
	return 0;
}
