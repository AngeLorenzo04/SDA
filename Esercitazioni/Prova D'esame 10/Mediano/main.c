#include "tree.h"
extern double Mediano(const Node* t);

int main(void) {

	const Node* t = TreeCreateEmpty();

	ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	t = TreeCreateRoot(e + 4,
		TreeCreateRoot(e + 2, 
			TreeCreateRoot(e + 1, NULL,NULL), 
			TreeCreateRoot(e + 3, NULL,NULL)),
		TreeCreateRoot(e + 6,
			TreeCreateRoot(e + 5, NULL, NULL),
			TreeCreateRoot(e + 7, NULL,NULL)));


	TreeWriteInOrder(t, stdout);

	Mediano(t);


	return 0;
}
