#include "tree.h"
#include <float.h>

static int TreeCountNode(const Node* t) {//conta nodi 

	if (TreeIsEmpty(t)) { //caso base
		return 0;
	}
	
	return 1 + TreeCountNode(TreeLeft(t)) + TreeCountNode(TreeRight(t)); //nodo + figli
}


static Node* TrovaNodo(int* index, const Node* t) {
	
	//ci spostiamo il piu possibile a sinistra

	if (TreeIsEmpty(t)) {
		return NULL;
	}

	Node* l = TrovaNodo(index, TreeLeft(t));
	if (!TreeIsEmpty(l)) {
		return l;
	}


	(*index)--;
	if (*index == 0) {
		return t;
	}
	
	//ci spostiamo a destra
	return TrovaNodo(index, TreeRight(t));
}


double Mediano(const Node* t) {

	if (TreeIsEmpty(t)) {

		return DBL_MAX;

	}

	int n = TreeCountNode(t);

	int index = (n + 1) / 2;

	if (n % 2 != 0) { // se n è dispari ritorna l'elemento al centro
		return *TreeGetRootValue(TrovaNodo(&index, t));
	}
	// se n è pari ritorna la media dei due numeri al centro
	Node* t1 = TrovaNodo(&index, t);
	index = ((n + 1) / 2) + 1;
	Node* t2 = TrovaNodo(&index, t);

	return (*TreeGetRootValue(t1) + *TreeGetRootValue(t2)) / 2.0;

	

}
