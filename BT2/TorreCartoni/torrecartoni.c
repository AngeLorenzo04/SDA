#include "torrecartoni.h"

static void Print(size_t* vcurr, size_t n) {
	for (int i = 0; i < n; i++) {
		printf("%i, ", vcurr[i]);
	}
	printf("\n");
}

static bool IsValid(const Cartone* c, size_t* vcurr, size_t* sum, size_t n, size_t e) {

	for (size_t j = 0; j < n; j++) {
		if (e == vcurr[j] || e == 0) {
			return false;
		}
	}

	if (c[e].l < *sum) {
		return false;
	}

	return true;
}

static void TorreCartoniRec(const Cartone* c, size_t n, size_t i, size_t* vcurr, size_t* vbest, size_t* sum) {

	if (i == n) {
		Print(vcurr, n);
		return;
	}

	if (i == 0) {
		*(sum) = 0;
	}

	for (size_t j = 0; j < n; j++) {
		if (IsValid(c, vcurr, sum, n, j)) {
			vcurr[i] = j;
			if(j != 0)
				(*sum) += c[j].p;
			TorreCartoniRec(c, n, i + 1, vcurr, vbest, sum);
		}
	}

}

void TorreCartoni(const Cartone* c, size_t n) {

	size_t* vcurr = malloc(n * sizeof(size_t));
	for (size_t i = 0; i < n; i++) {
		vcurr[i] = n;
	}
	size_t* vbest = malloc(n * sizeof(size_t));
	for (size_t i = 0; i < n; i++) {
		vbest[i] = n;
	}
	size_t sum = 0;
	TorreCartoniRec(c, n, 0, vcurr, vbest, &sum);
}