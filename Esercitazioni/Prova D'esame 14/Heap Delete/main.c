#include "minheap.h"
extern void HeapDeleteNode(Heap* h, int k);
int main(void) {

	Heap* h = HeapCreateEmpty();

	const ElemType elem[] = {32,5,4,6,12,23};

	for (size_t i = 0; i < 6; i++) {
		
		HeapMinInsertNode(h, elem + i);
	}

	HeapWriteStdout(h);
	HeapDeleteNode(h, 5);
	HeapWriteStdout(h);

	HeapDeleteNode(h, 1);
	HeapWriteStdout(h);
	

	return 0;
}
