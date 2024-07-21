#include "minheap.h"
#include <stdlib.h>
static void  HeapMinHeapifyRec(Heap* h, int i) {

	if (i > (int)(h->size - 1)/2) {
		
		HeapMinHeapifyRec(h,0);

	}

	int left = HeapLeft(i);
	int right = HeapRight(i);


	if (left < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, left)) > 0) {

		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, left));
		HeapMinHeapifyRec(h, left);
		
	}
	else if (right < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, right)) > 0) {

		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, right));
		HeapMinHeapifyRec(h, right);
		
	}
	
	
	return;

}

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	Heap* ris = HeapCreateEmpty();
	ris->data = malloc(v_size * sizeof(ElemType));
	ris->size = v_size;

	if (v == NULL || v_size == 0) {

		return ris;

	}

	for (size_t i = 0; i < ris->size; i++) {

		ris->data[i] = v[i];

	}

	HeapWriteStdout(ris);

	HeapMinHeapifyRec(ris,0);

	return ris;

}



/*

		5                 3                  2             1     RIS: 1 2 3 5 3
	   / \               / \                / \           / \
	  3   3             2   3              1   3         2   3
	 / \               / \                / \           / \
	2   1             5	  1              5   3         5   3

*/