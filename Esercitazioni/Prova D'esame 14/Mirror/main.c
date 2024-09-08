#include "tree.h"
extern bool TreeIsMirror(Node* t);
int main(void) {

	int e[] = {0,1,2,3,4,5};

	Node* t1 = TreeCreateEmpty();

	t1 = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 4, NULL,NULL),
			TreeCreateRoot(e + 2, NULL, NULL)),
		TreeCreateRoot(e + 1, 
			TreeCreateRoot(e + 2, NULL, NULL),
			TreeCreateRoot(e + 4, NULL, NULL)));

	Node* t2 = TreeCreateEmpty();

	t2 = TreeCreateRoot(e + 0,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 4, NULL, NULL),
			TreeCreateRoot(e + 2, NULL, NULL)),
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 4, NULL, NULL),
			TreeCreateRoot(e + 2, NULL, NULL)));
	TreeIsMirror(t1);
	TreeIsMirror(t2);

	return 0;
}
