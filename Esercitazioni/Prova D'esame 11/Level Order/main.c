#include "tree.h"
extern void LevelOrder(const Node* t);

int main(void) {
	
	ElemType data[] = { 0,1,2,3,4,5,6,7,8,9 };

	Node*t = TreeCreateEmpty();

	t = TreeCreateRoot(data + 7,
		TreeCreateRoot(data + 4,
			TreeCreateRoot(data + 2,NULL,NULL),
			TreeCreateRoot(data + 5,NULL,NULL)),
		TreeCreateRoot(data + 8,NULL,NULL));

	LevelOrder(t);

	return 0;
}