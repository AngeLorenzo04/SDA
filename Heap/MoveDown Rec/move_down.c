#include "minheap.h"
#include <stdlib.h>
#include <limits.h>

static int MinChild(Heap* h, int i) {

	if (HeapLeft(i) > (int)h->size  && HeapRight(i) > (int)h->size) {
		return INT_MIN;
	}

	if (HeapLeft(i) > (int)h->size) {
		return HeapRight(i);
	}
	if (HeapRight(i) > (int)h->size) {
		return HeapLeft(i);
	}

	if (ElemCompare(HeapGetNodeValue(h, HeapLeft(i)), HeapGetNodeValue(h, HeapRight(i))) > 0) {
		return HeapRight(i);
	}

	return HeapLeft(i);

}

void HeapMinMoveDownRec(Heap* h, int i) {

	if (i > (int)(h->size + 1) / 2) {
		return;
	}

	int youngest = MinChild(h, i);

	if (youngest == INT_MIN) {
		return;
	}

	if (youngest < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, youngest)) > 0) {
		
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, youngest));
		HeapMinMoveDownRec(h, youngest);
	}

	return;

}

		 