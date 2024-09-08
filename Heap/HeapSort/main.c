#include "minheap.h"
#include <stdlib.h>
#include <limits.h>

extern void HeapMinHeapsort(Heap* h);


int main(void) {

	Heap* h = HeapCreateEmpty();

	const ElemType elem[] = {32,5,4,6,12,23};

	for (size_t i = 0; i < 6; i++) {
		
		HeapMinInsertNode(h, elem + i);
	}

	printf("Heap del porcoddio: \n");
	HeapWriteStdout(h);

	ElemType* e = malloc(sizeof(ElemType));
	HeapMinHeapsort(h);

	printf("Heap della porcaccia la madonna: \n");
	HeapWriteStdout(h);

	return 0;
}

/*

    

*/

/*

		5                 3                  3             1   RIS: 1 2 3 5 3
	   / \               / \                / \           / \
      3   3             2   3              2  3          2	 3
     / \               / \                / \           / \
    2   1             5	  1              5   1         5   3
	 
*/