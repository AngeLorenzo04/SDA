#include "tree.h"
extern int CountDominant(const Node* t);
int main(void) {

	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 77};

	Node* t = TreeCreateEmpty();
	t = TreeCreateRoot(e + 12, 
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 0, 
				TreeCreateRoot(e + 22,NULL,NULL), 
				TreeCreateRoot(e + 8, NULL,NULL)), 
			TreeCreateRoot(e + 2,
				TreeCreateRoot(e + 9, NULL,NULL),
				NULL)), 
		TreeCreateRoot(e + 21,
			TreeCreateRoot(e + 5, NULL, NULL),
			TreeCreateRoot( e + 18, NULL,NULL)));
	
	
	
	TreeWriteInOrder(t, stdout);/* dal nodo con valore minore a quello con valore maggiore /\    */
	TreeWritePostOrder(t, stdout);/*dal basso all alto -> dalle foglie alla radice		  /  \  */
	TreeWritePreOrder(t, stdout);/*dal alto al basso -> dalla radice alle foglie		   ||  */

	printf("numero di nodi dominanti: %d",	CountDominant(t));

	return 0;
}