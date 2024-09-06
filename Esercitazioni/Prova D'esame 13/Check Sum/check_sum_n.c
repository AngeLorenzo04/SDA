#include "tree.h"
void CheckSumNRec(const Node* t, int n, bool* ris, Node* e) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (t != e && (*TreeGetRootValue(e) + *TreeGetRootValue(t) == n)) {
		*ris = true;
		return;
	}

	CheckSumNRec(TreeLeft(t), n, ris, e);
	CheckSumNRec(TreeRight(t), n, ris, e);
}


void SendNode(const Node* t,const Node* tmp, int n, bool* ris) {

	if (TreeIsEmpty(tmp)) {
		return;
	}
	
	CheckSumNRec(t, n, ris, tmp);

	SendNode(t, TreeLeft(tmp), n, ris);
	SendNode(t, TreeRight(tmp), n, ris);
}

bool CheckSumN(const Node* t, int n) {

	bool ris = false;

	const Node* tmp = t;
	SendNode(t, tmp, n, &ris);

	return ris;

}