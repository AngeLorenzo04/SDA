#include "minheap.h"
#include <stdlib.h>
extern void HeapMinMoveUpRec(Heap* h, int i);

int main(void) {

	Heap* h = HeapCreateEmpty();
	h->data = malloc(5 * sizeof(ElemType));
	h->size = 5;

	const ElemType elem1[] = { 4, 6, 1, 1, 12, 23 };
	const ElemType elem[] = {2,1,3,5,3};

	for (size_t i = 0; i < 5; i++) {
		
		h->data[i] = ElemCopy(elem + i);
	}

	printf("Heap del porcoddio: \n");
	HeapWriteStdout(h);

	HeapMinMoveUpRec(h, 1);

	printf("Heap della porcaccia la madonna: \n");
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