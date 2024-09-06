#include "tree.h"

size_t CalcolaAltezza(const Node* t) {

	if (TreeIsEmpty(t)) {
		return 0;
	}
	return 1 + CalcolaAltezza(TreeLeft(t)) + CalcolaAltezza(TreeRight(t));



}


void StampaXLevel(const Node* t, size_t level, size_t i) {

	if (i == level && !TreeIsEmpty(t)) {
	  ElemWrite(TreeGetRootValue(t),stdout);
	  printf(" ");
	}

	if (TreeIsEmpty(t) || i > level) {
		return;
	}

	StampaXLevel(TreeLeft(t), level, i + 1);
	StampaXLevel(TreeRight(t), level, i + 1);

}

void LevelOrder(const Node* t) {
	
	if (t == NULL) {
		return;
	}

	size_t a = CalcolaAltezza(t);

	for (size_t j = 0; j < a; j++) {
		StampaXLevel(t, j, 0);
	}



}