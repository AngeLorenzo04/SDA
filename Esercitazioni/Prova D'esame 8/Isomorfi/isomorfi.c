#include "tree.h"

static bool IsomorfiRec(const Node* t1, const Node* t2, bool* ris) {
	
	
	//verifica il valore

	if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {

		*ris = false;
		return ris;

	}

	//verifica se ci troviamo in una foglia
	if (TreeIsLeaf(t1) || TreeIsLeaf(t2)) {
		return ris;
	}

	if (!((ElemCompare(TreeGetRootValue(TreeLeft(t1)), TreeGetRootValue(TreeRight(t2))) ||
		ElemCompare(TreeGetRootValue(TreeLeft(t1)), TreeGetRootValue(TreeLeft(t2)))) && (
			ElemCompare(TreeGetRootValue(TreeRight(t1)), TreeGetRootValue(TreeRight(t2))) ||
			ElemCompare(TreeGetRootValue(TreeRight(t1)), TreeGetRootValue(TreeLeft(t2)))))) {

		*ris = false;
		return ris;

	}


	
	return ris;


}

bool Isomorfi(const Node* t1, const Node* t2) {

	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	bool ris = true;

	IsomorfiRec(t1, t2, &ris);

	return ris;


}