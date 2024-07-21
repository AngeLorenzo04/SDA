#include "tree.h"


static const ElemType* BstTreeMaxRec(const Node* n, const ElemType* e) {

	if (TreeIsEmpty(n)) {
		return e;
	}

	e = TreeGetRootValue(n);

	BstTreeMaxRec(TreeRight(n), e);

}

const ElemType* BstTreeMax(const Node* n) {
	
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	const ElemType maxvalue;

	return BstTreeMaxRec(n, &maxvalue);

}


static void TreeMaxRec(const Node* n, const ElemType** e) {

	if (TreeIsEmpty(n)) {
		return;
	}

	if (ElemCompare(TreeGetRootValue(n), *e) > 0) {
		*e = TreeGetRootValue(n);
	}

	TreeMaxRec(TreeLeft(n), e);
	TreeMaxRec(TreeRight(n), e);

}

const ElemType* TreeMax(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* e = TreeGetRootValue(n);

	TreeMaxRec(n, &e);

	return e; 
}