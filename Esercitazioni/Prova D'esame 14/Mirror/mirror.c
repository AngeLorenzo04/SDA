#include "tree.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>

size_t TreeHeigth(Node* t) {

	if (TreeIsEmpty(t)) {
		return 0;
	}

	size_t lh = TreeHeigth(TreeLeft(t));
	size_t rh = TreeHeigth(TreeRight(t));

	if (lh > rh) {
		return lh + 1;
	}

	return rh + 1;

}

bool CheckIfLvlValid(int* vett, size_t level) {

	size_t dim = pow(2,level);
	size_t j = dim;

	for (size_t i = 0; i < dim / 2; i++) {

		if (vett[i] != vett[j - 1]) {
			return false;
		}

		j--;
	}

	return true;
}

void FillVett(Node* t, int* vett, size_t level, size_t i, int* j) {

	if (i > level) {
		return;
	}

	if (i == level) {
		if (TreeIsEmpty(t)) {
			vett[*j] = INT_MAX;
		}
		else {
			vett[*j] = *TreeGetRootValue(t);
		}
		(*j)++;
	}

	FillVett(TreeLeft(t), vett, level, i + 1, j);
	FillVett(TreeRight(t), vett, level, i + 1, j);

}

bool TreeIsMirror(Node* t) {

	size_t altezza = TreeHeigth(t);
	int* vett = calloc(altezza, sizeof(int));
	
	for (size_t i = 0; i < altezza; ++i) {

		int j = 0;
		FillVett(t, vett, i, 0, &j);

		if (!CheckIfLvlValid(vett, i)) {
			free(vett);
			return false;
		}

	}
	free(vett);
	return true;
}