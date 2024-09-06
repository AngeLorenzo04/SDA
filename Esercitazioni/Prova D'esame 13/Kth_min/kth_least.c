#include "minheap.h"
#include <stdlib.h>
#include <limits.h>

ElemType HeapSortFindMin(Heap* h) {

	ElemType min = *HeapGetNodeValue(h, 0);

	h->data[0] = *HeapGetNodeValue(h, h->size - 1);

	h->size--;

	HeapMinMoveDown(h, 0);

	return min;
}

Heap* HeapCopy(const Heap* h) {
	Heap* copia = HeapCreateEmpty();

	for (size_t i = 0; i < h->size; i++) {
		HeapMinInsertNode(copia, HeapGetNodeValue(h, i));
	}

	return copia;

}

ElemType KthLeast(const Heap* h, int k) {

	ElemType ris;
	Heap* tmp = HeapCopy(h);

	for (int i = 0; i < k ; i++) {

		ris = HeapSortFindMin(tmp);

	}

	HeapDelete(tmp);
	return ris;

}

