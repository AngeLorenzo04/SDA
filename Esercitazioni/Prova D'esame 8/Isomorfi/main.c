#include "tree.h"
#include <stdlib.h>
extern bool Isomorfi(const Node* t1, const Node* t2);

int main(void) {

	Node* t1 = TreeCreateEmpty();
	Node* t2 = TreeCreateEmpty();

	const ElemType* e[] = { 0,1,2,3,4,5,6,7,8,9 };

	t1 = TreeCreateRoot(e + 1, TreeCreateRoot(e + 2, TreeCreateRoot(e + 4, NULL,NULL), NULL), TreeCreateRoot(e + 5, NULL, NULL));
	t2 = TreeCreateRoot(e + 1, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 2, TreeCreateRoot(e + 4, NULL,NULL), NULL));



	printf("t1:\n");
	TreeWritePreOrder(t1, stdout);
	printf("\nt2:\n ");
	TreeWritePreOrder(t2, stdout);

	Isomorfi(t1, t2);


	return 0;

}