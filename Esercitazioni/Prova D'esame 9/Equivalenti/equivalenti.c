#include "tree.h"

static size_t TreeNumberChild(const Node* t) {

	if (TreeIsLeaf(t)) {
		return 0;
	}

	if (TreeLeft(t) == NULL || TreeRight(t) == NULL) {
		return 1;
	}

	return 2;

}


static bool EquivalentiRec(const Node* t1, const Node* t2, bool* ris) {

	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) { //caso base
		return *ris;
	}
	else if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) { //caso che rientra nella condizione della struttura
		return false;
	}


	//controllo se i nodi hanno lo stesso valore
	if (!TreeIsLeaf(t1) || !TreeIsLeaf(t2)) {

		//controllo stessa struttura
		if (TreeNumberChild(t1) != TreeNumberChild(t2)) {
			*ris = false;
			return *ris;
		}

		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) != 0) {
			*ris = false;
			return *ris;
		}

		

	}
	else {
		//controllo se le foglie sono multiple
		if (ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) > 0 && t1->value % t2->value != 0) {
			*ris = false;
			return *ris;
		}
		else if (ElemCompare(TreeGetRootValue(t2), TreeGetRootValue(t1)) > 0 && t2->value % t1->value != 0) {
			*ris =  false;
			return *ris;
		}
	}

	EquivalentiRec(TreeLeft(t1), TreeLeft(t2), ris);
	EquivalentiRec(TreeRight(t1), TreeRight(t2), ris);
}


bool Equivalenti(const Node* t1, const Node* t2) {

	bool ris = true;

	return EquivalentiRec(t1, t2, &ris);



}