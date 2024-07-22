#include "minheap.h"
#include<string.h>
bool HeapMinPop(Heap* h, ElemType* e) {
	
	if (HeapIsEmpty(h)) {
		return false;              
	}

	memcpy(e, HeapGetNodeValue(h, 0), sizeof(ElemType));

	int i = 0;

	int indexlast = h->size - 1;
	


	ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, indexlast));
	ElemDelete(HeapGetNodeValue(h, indexlast));
	h->size--;
	HeapMinMoveDown(h, i);

	return true;
	
}