#include "tree.h"

static void BstTreeMinRec(const Node* n, const ElemType** e) {

	if (TreeIsEmpty(n)) {
		return;
	}

	*e = TreeGetRootValue(n);

	BstTreeMinRec(TreeLeft(n), e);
	
	return;

}
const ElemType* BstTreeMin(const Node* n) {

	if (n == NULL) {
		return NULL;
	}

	const ElemType* e = TreeGetRootValue(n);

	BstTreeMinRec(n, &e);

	return e;

}

static void TreeMinRec(const Node* n, const ElemType** e) {

	if (TreeIsEmpty(n)) {

		return;
	}

	if (ElemCompare(TreeGetRootValue(n), *e) <= 0) {

		*e = TreeGetRootValue(n);

	}

	TreeMinRec(TreeLeft(n), e);
	TreeMinRec(TreeRight(n), e);

}

const ElemType* TreeMin(const Node* n) {

	if (n == NULL) {
		return NULL;
	}

	const ElemType* e = TreeGetRootValue(n);

	TreeMinRec(n, &e);

	return e;

}