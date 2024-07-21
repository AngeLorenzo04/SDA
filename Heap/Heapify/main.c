#include "minheap.h"
#include <stdlib.h>
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void) {

	Heap* h = HeapCreateEmpty();
	h->data = malloc(5 * sizeof(ElemType));
	h->size = 5;

	const ElemType elem1[] = { 4, 6, 1, 1, 12, 23 };
	const ElemType elem[] = { 5,3,3,2,1 };



	h = HeapMinHeapify(elem1, 6);
	h = HeapMinHeapify(elem, 5);

	printf("Heap del porcoddio: \n");
	HeapWriteStdout(h);

	return 0;
}

/*

		5                 3                  2             1   RIS: 1 2 3 5 3
	   / \               / \                / \           / \
      3   3             2   3              1   3         2   3
     / \               / \                / \           / \
    2   1             5	  1              5   3         5   3
	 
*/