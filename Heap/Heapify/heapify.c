#include "minheap.h"
#include <stdlib.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {

	
	Heap* ris = HeapCreateEmpty();

	for (size_t i = 0; i < v_size; i++) {

		HeapMinInsertNode(ris, v + i);

	}

	return ris; 

}



/*

		5                 3                  2             1     RIS: 1 2 3 5 3
	   / \               / \                / \           / \
	  3   3             2   3              1   3         2   3
	 / \               / \                / \           / \
	2   1             5	  1              5   3         5   3

*/