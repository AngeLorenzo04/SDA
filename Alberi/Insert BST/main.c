#include "tree.h"

extern Node* BstInsert(const ElemType* e, Node* n);
extern Node* BstInsertRec(const ElemType* e, Node* n);

int main(void) {

	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, -4};

	Node* t = TreeCreateEmpty();
	t = BstInsertRec(e + 4, t);
	t = BstInsertRec(e + 1, t);
	t = BstInsertRec(e + 7, t);
	t = BstInsertRec(e + 22, t);
	t = BstInsertRec(e + 2, t);
	t = BstInsertRec(e + 1, t);
	t = BstInsertRec(e + 3, t);
	t = BstInsertRec(e + 8, t);
	t = BstInsertRec(e + 7, t);
	t = BstInsertRec(e + 5, t);
	t = BstInsertRec(e + 12, t);
	//t = TreeCreateRoot(e + 4,
	//	TreeCreateRoot(e + 3, TreeCreateRoot(e + 1, TreeCreateRoot(e + 1,NULL,NULL), TreeCreateRoot(e + 2,NULL,NULL)), NULL),
	//	TreeCreateRoot(e + 7, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 8, NULL, NULL)));

	TreeWriteInOrder(t, stdout);/* dal nodo con valore minore a quello con valore maggiore /\    */
	TreeWritePostOrder(t, stdout);/*dal basso all alto -> dalle foglie alla radice		  /  \  */
	TreeWritePreOrder(t, stdout);/*dal alto al basso -> dalla radice alle foglie		   ||  */
	return 0;
}