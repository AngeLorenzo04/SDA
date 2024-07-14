#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"

int main(void) {

	size_t retsize;
	Gioiello* a = CompraGioielli("gioielli_1.txt", 121, &retsize);

	for (size_t i = 0; i < retsize; i++) {

		printf("idice: %i, peso: %f, prezzo: %f\n", a[i].codice, a[i].peso, a[i].prezzo);

	}



	return 0;
}
