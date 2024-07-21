#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {

	Node* nuovo = TreeCreateRoot(e,NULL,NULL);
	if (n == NULL) {
		return nuovo;
	}

	Node* padre = NULL;
	Node* curr = n;
	while (!TreeIsEmpty(curr)) {
		padre = curr;
		if (ElemCompare(e, TreeGetRootValue(curr)) <= 0) {
			curr = curr->left;
		}
		else {
			curr = curr->right;
		}

	}


	if (ElemCompare(e, TreeGetRootValue(padre)) <= 0) {
		padre->left = nuovo;
	}
	else {
		padre->right = nuovo;
	}

	return n;

}
Node* BstInsertRec(const ElemType* e, Node* n) {

	Node* nuovo = TreeCreateRoot(e, NULL, NULL);

	if (TreeIsEmpty(n)) {
		return nuovo;
	}

	if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		n->left = BstInsertRec(e, TreeLeft(n));
	}
	else {
		n->right = BstInsertRec(e, TreeRight(n));
	}
	
	
	TreeDelete(nuovo);
	return n;

}