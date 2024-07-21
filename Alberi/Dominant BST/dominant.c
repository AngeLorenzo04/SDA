
#include "tree.h"

bool IsDominant(const Node* t) {

	if (TreeLeft(t) == NULL && TreeLeft(t) == NULL) {
		return false;
	}


	ElemType sum;
	if (TreeLeft(t) == NULL) {
		sum = *TreeGetRootValue(TreeRight(t));
	}
	else if (TreeRight(t) == NULL) {
		sum = *TreeGetRootValue(TreeLeft(t));
	}else {
		sum = *TreeGetRootValue(TreeLeft(t)) + *TreeGetRootValue(TreeRight(t));
	}

	return(ElemCompare(TreeGetRootValue(t), &sum) > 0);

}

void CountDominantRec(const Node* t, int* cnt) {


	if (TreeIsLeaf(t)) {
		return;
	}
	
	if (IsDominant(t)) {
		(*cnt)++;
	}
	t = TreeLeft(t);
	CountDominantRec(t,cnt);
	t = TreeRight(t);
	CountDominantRec(t,cnt);

}

int CountDominant(const Node* t) {

	if (t == NULL || TreeIsEmpty(t)) {
		return 0;
	}

	int cnt = 0;
	CountDominantRec(t, &cnt);
	return cnt;

 }
