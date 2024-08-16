#include "tree.h"
extern bool Equivalenti(const Node* t1, const Node* t2);

int main(void) {

	const Node* t1 = TreeCreateEmpty();
	const Node* t2 = TreeCreateEmpty();

	const ElemType* e[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};

	t1 = TreeCreateRoot(e + 1, TreeCreateRoot(e + 2, TreeCreateRoot(e + 4,NULL,NULL), NULL), TreeCreateRoot(e + 5, NULL,NULL));
	t2 = TreeCreateRoot(e + 1, TreeCreateRoot(e + 2, TreeCreateRoot(e + 4,TreeCreateRoot(e + 3,NULL,NULL), NULL), NULL), TreeCreateRoot(e + 5, NULL, NULL));


	TreeWritePostOrder(t1, stdout);
	TreeWritePostOrder(t2, stdout);

	Equivalenti(t1, t2);
	
	return 0;
}