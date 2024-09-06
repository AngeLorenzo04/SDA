#include "minheap.h"

extern Heap* MergeHeap(const Heap* h1, const Heap* h2) {

	Heap* ris = HeapCreateEmpty();

	if (h1->size > h2->size) {

		for (size_t i = 0; i < h1->size; i++) {

			HeapMinInsertNode(ris, HeapGetNodeValue(h1, i));
			if (i < h2->size) {
				HeapMinInsertNode(ris, HeapGetNodeValue(h2, i));
			}

		}

	}
	else {
		for (size_t i = 0; i < h2->size; i++) {

			HeapMinInsertNode(ris, HeapGetNodeValue(h2, i));
			if (i < h1->size) {
				HeapMinInsertNode(ris, HeapGetNodeValue(h1, i));
			}

		}
	}

	return ris;

}
