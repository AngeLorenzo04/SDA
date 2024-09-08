#include "minheap.h"

static void MoveDown(Heap* h, int i) {

	int index_lchild = HeapLeft(i);
	int index_rchild = HeapRight(i);

	if (index_lchild >= (int)h->size) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, index_rchild));
		return;
	}
	if (index_rchild >= (int)h->size) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, index_lchild));
		return;
	}

	if (ElemCompare(HeapGetNodeValue(h, index_lchild), HeapGetNodeValue(h, index_rchild)) > 0) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, index_rchild));
		return;
	}

	ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, index_lchild));
	return;
}

static void HeapMinHeapsortRec(Heap* h) {

	if (h->size == 2) {
		return;
	}

	int primo_index = 0;
	int ultimo_index = h->size - 1;

	ElemSwap(HeapGetNodeValue(h,primo_index),HeapGetNodeValue(h,ultimo_index));
	h->size--;
	MoveDown(h, primo_index);

	

	HeapMinHeapsortRec(h);

}


void HeapMinHeapsort(Heap* h) {

	int realsize = h->size;

	HeapMinHeapsortRec(h);

	h->size = realsize;

	return;
}