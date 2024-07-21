#include "minheap.h"
#include <stdlib.h>
#include <limits.h>

extern void HeapMinMoveDownRec(Heap* h, int i);
int main(void) {

	Heap* h = HeapCreateEmpty();
	h->data = malloc(5 * sizeof(ElemType));
	h->size = 5;

	const ElemType elem1[] = { 4, 6, 1, 1, 12, 23 };
	const ElemType elem[] = {32,5,4,6,12,23};

	for (size_t i = 0; i < 6; i++) {
		
		h->data[i] = ElemCopy(elem + i);
	}

	printf("Heap del porcoddio: \n");
	HeapWriteStdout(h);

	HeapMinMoveDownRec(h, 0);

	printf("Heap della porcaccia la madonna: \n");
	HeapWriteStdout(h);

	return 0;
}

/*

		5                 3                  3             1   RIS: 1 2 3 5 3
	   / \               / \                / \           / \
      3   3             2   3              2  3         2   3
     / \               / \                / \           / \
    2   1             5	  1              5   1         5   3
	 
*/