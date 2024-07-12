#include "torrecartoni.h"

static void IsBest(size_t n, size_t *vcurr, size_t *vbest, size_t *hmax, size_t h) {

	for (size_t k = 0; k < n; k++) {
		if (vcurr[k] == n + 1 && vcurr[k + 1] == n + 1) {
			return;
		}
	}

	if (h > *hmax) {
		memcpy(vbest, vcurr,n * sizeof(size_t));
		*hmax = h;
	}
}

static void Print(size_t* vbest, size_t n, size_t hmax) {

	for (size_t i = 0; i < n; i++)
	{
		if (vbest[i] != n + 1) {
			printf("%zu\n", vbest[i] - 1);
		}

	}

	printf("Altezza: %zu", hmax);

}

static bool CheckPresenza(size_t* vcurr, size_t n, size_t j) {

	for (size_t k = 0; k < n; k++) {
		if (vcurr[k] == j) {
			return false;
		}
	}

	return true;
}

static bool CheckPeso(const Cartone* c, size_t j, size_t sum) {

	return (c[j].l > sum);
	
}


static void TorreCartoniRec(const Cartone* c, size_t n, size_t i, size_t* vcurr, size_t* vbest, size_t* sum, size_t* h, size_t* hmax) {

	if (i == n) {
		IsBest(n, vcurr, vbest, hmax, *h);
		return;
	}

	for (size_t j = 1; j <= n; j++) {
		
		if (CheckPresenza(vcurr, n, j) && CheckPeso(c,j-1,*sum)) {
			vcurr[i] = j;
			*sum+= c[j-1].p;
			*h+= c[j-1].a;
			TorreCartoniRec(c, n, i + 1, vcurr, vbest, sum,h,hmax);
			vcurr[i] = n+1;
			*sum -= c[j-1].p;
			*h -= c[j-1].a;
		}
		else {
			TorreCartoniRec(c, n, i + 1, vcurr, vbest, sum, h,hmax);
		}

	}

}

void TorreCartoni(const Cartone* c, size_t n) {

	size_t* vcurr = malloc(n * sizeof(size_t));
	for (size_t i = 0; i < n; i++) {
		vcurr[i] = n + 1;
	}

	size_t* vbest = malloc(n * sizeof(size_t));
	for (size_t i = 0; i < n; i++) {
		vbest[i] = n + 1;
	}

	size_t sum = 0;
	size_t h = 0;
	size_t hmax = 0;
	TorreCartoniRec(c, n, 0, vcurr, vbest, &sum, &h, &hmax);
	Print(vbest, n, hmax);
	free(vcurr);
	free(vbest);
}