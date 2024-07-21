#include "tree.h"
#include <stdlib.h>

static Node* TreeMax(Node* p,Node* n) {

	if (TreeRight(n) != NULL) {
		return TreeMax(n,TreeRight(n));
	}

	if (n == p->left) {
		p->left = n->left;
	}
	else {
		p->right = n->left;
	}

	return n;

}

static Node* DeleteNode(Node* n) {

	Node* nuovonodo = malloc(sizeof(Node));

	if (n->left == NULL && n->right == NULL) { //se non ha figli, liberare la memoria
		TreeDelete(n);
		return NULL;
	}
	//se ha solo un figlio ritornare il nuovo nodo da sostituire al vecchio
	else if(n->left == NULL) { 
		nuovonodo = n->right;
	}
	else if (n->right == NULL) {
		nuovonodo = n->left;
	}
	//se ha 2 filgi sostituirlo con il valore più grande nel sottoalber sinistro
	else {
		nuovonodo = TreeMax(n,TreeLeft(n));//trova il valore da sostituire e aggiorna i figli del padre
		ElemSwap(&n->value, &nuovonodo->value);//scambia i valori con il nodo da eliminare e quello trovato
		free(nuovonodo);//libera la memoria
		return n;
	}

	free(n);

	return nuovonodo;

}

Node* DeleteBstNode(Node* n, const ElemType* key) {

	if (n == NULL || key == NULL) { //controlli 
		return NULL;
	}

	//cerca il nodo da eliminare
	if (ElemCompare(TreeGetRootValue(n), key) > 0) {
		
		n->left = DeleteBstNode(TreeLeft(n), key);

	}
	else if (ElemCompare(TreeGetRootValue(n), key) < 0) {
		n->right = DeleteBstNode(TreeRight(n), key);
	}
	else {
		n = DeleteNode(n); //elimina il nodo trovato
	}

	return n;
	
}