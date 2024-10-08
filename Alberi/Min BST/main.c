#include "tree.h"
extern Node* DeleteBstNode(Node* n, const ElemType* key);
int main(void) {

	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 77};  

	Node* t = TreeCreateEmpty();

	t = TreeCreateRoot(e + 4, 
		TreeCreateRoot(e + 3,
			TreeCreateRoot(e + 1,
				TreeCreateRoot(e + 1,NULL,NULL),
				TreeCreateRoot(e + 2,NULL,NULL)),NULL),
		TreeCreateRoot(e + 7,
			TreeCreateRoot(e + 5,NULL,
				TreeCreateRoot(e + 6, NULL,NULL)), 
			TreeCreateRoot(e + 8, NULL,NULL)));


	Node* t1 = TreeCreateEmpty();
	t1 = TreeCreateRoot(e + 21,
		TreeCreateRoot(e + 22,
			TreeCreateRoot(e + 4,
				TreeCreateRoot(e + 2, NULL, NULL),
				TreeCreateRoot(e + 15, NULL, NULL)),
			TreeCreateRoot(e + 20,
				TreeCreateRoot(e + 19, NULL, NULL),
				NULL)),
		TreeCreateRoot(e + 21,
			TreeCreateRoot(e + 5, NULL,
				TreeCreateRoot(e + 6,NULL,NULL)),
			TreeCreateRoot(e + 18, NULL, NULL)));

	
	
	
	/*TreeWriteInOrder(t, stdout); dal nodo con valore minore a quello con valore maggiore / \    */
	/*TreeWritePostOrder(t, stdout);/dal basso all alto -> dalle foglie alla radice		  /   \  */
	/*TreeWritePreOrder(t, stdout);/*dal alto al basso -> dalla radice alle foglie		   |_|  */

	printf("albero bst:\n");
	TreeWritePostOrder(t, stdout);
	
	printf("\nalbero dopo la delete:\n");
	t = DeleteBstNode(t,e + 3);
	TreeWritePostOrder(t, stdout);



	

	return 0;
}