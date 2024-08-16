#include "colori.h"

static bool IsValid(char* vcurr, const struct Matrix* m, size_t j, size_t i) {

	return !(E(m, i, j) == 1 && vcurr[i] == vcurr[j]);
}

static void Stampa(char* vcurr, const struct Matrix* m) {

	for (size_t i = 0; i < m->size; i++) {

		printf("%d -> %d;", i, vcurr[i]);
		if (i != m->size - 1) {
			printf(" ");
		}

	}
	printf("\n");
}

static void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size, char* vcurr, int* nsol,size_t i, size_t j, size_t* k) {



	if (i == m->size - 1) {
		return;
	}

	if (i != m->size - 2) {

		for (; *k < c_size; (*k)++) {

			vcurr[i] = c[*k];

			if (j != m->size - 1) {

				vcurr[j] = 'r';
				if (IsValid(vcurr, m, j, i)) {
					MappaColoriRec(m, c, c_size, vcurr, nsol, i, j + 1, k);
				}

				vcurr[j] = 'v';
				if (IsValid(vcurr, m, j, i)) {
					MappaColoriRec(m, c, c_size, vcurr, nsol, i, j + 1, k);
				}

			}
			else {
				MappaColoriRec(m, c, c_size, vcurr, nsol, i + 1, i + 2, k);
			}
		}
	}




}


int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {

	char* vcurr = calloc(m->size, sizeof(bool));
	int nsol = 0;
	size_t k = 0;
	MappaColoriRec(m, c, c_size, vcurr, &nsol,0,1,&k);

	free(vcurr);

	return nsol;

}

/*

	c = {'r','v'}

	aree = [0, 1, 2]


	m = [1, 1, 1
		 1, 1, 0
		 1, 0, 1]




*/