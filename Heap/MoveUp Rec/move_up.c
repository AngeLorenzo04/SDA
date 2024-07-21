#include "minheap.h"
#include <stdlib.h>

void HeapMinMoveUpRec(Heap* h, int i) {

	int parent = HeapParent(i);


	if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, parent)) < 0) {

		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, parent));

		HeapMinMoveUpRec(h, parent);

	}

	return;

}
