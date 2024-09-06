#include "tree.h"

//disegna 2 alberi
extern bool CheckSumN(const Node* t, int n);

int main(void) {

	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 77};  

	Node* t = TreeCreateEmpty();

	t = TreeCreateRoot(e + 7,
		TreeCreateRoot(e + 6,
			TreeCreateRoot(e + 2,
				TreeCreateRoot(e + 1, NULL, NULL),NULL),
			TreeCreateRoot(e + 5,NULL,NULL)), 
		TreeCreateRoot(e + 8,NULL,NULL));	
	
	/*TreeWriteInOrder(t, stdout); dal nodo con valore minore a quello con valore maggiore / \    */
	/*TreeWritePostOrder(t, stdout);/dal basso all alto -> dalle foglie alla radice		  /   \  */
	/*TreeWritePreOrder(t, stdout);/*dal alto al basso -> dalla radice alle foglie		   |_|  */

	TreeWritePreOrder(t,stdout);
	
	CheckSumN(t, 4);
	CheckSumN(t, 6);
	CheckSumN(t, 7);


	

	return 0;
}