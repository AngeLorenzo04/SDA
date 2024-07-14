#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"

size_t ElementOfFile(FILE* f) {

	int tmp;
	float tmp1;
	size_t cnt = 0;
	while (1) {

		if (fscanf(f, "%d %f %f", &tmp, &tmp1, &tmp1) != 3)
			break;
		cnt++;

	}
	rewind(f);

	return cnt;
}


void Popola(Gioiello* Gioielli, FILE* f) {

	size_t i = 0;
	while (1) {

		if (fscanf(f, "%d %f %f", &Gioielli[i].codice, &Gioielli[i].peso, &Gioielli[i].prezzo) != 3)
			break;
		i++;

	}
	rewind(f);
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {

	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return NULL;
	}


	Gioiello* Gioielli = calloc(sizeof(Gioiello), ElementOfFile(f));

	Popola(Gioielli, f);

	float* appetibilita = malloc(sizeof(float) * ElementOfFile(f));

	for (size_t i = 0; i < ElementOfFile(f); ++i) {

		appetibilita[i] = (float)(Gioielli[i].prezzo / Gioielli[i].peso);

	}


	//Ordino in funzione delle appetibilità

	float tmp;
	Gioiello tmp1;

	for (size_t i = 1; i < ElementOfFile(f); i++) {

		if (appetibilita[i] < appetibilita[i - 1]) {

			tmp = appetibilita[i];
			appetibilita[i] = appetibilita[i - 1];
			appetibilita[i - 1] = tmp;

			tmp1 = Gioielli[i];
			Gioielli[i] = Gioielli[i - 1];
			Gioielli[i - 1] = tmp1;

		}

	}

	Gioiello* ris = malloc(sizeof(Gioiello) * ElementOfFile(f));



	size_t i = 0;
	size_t j = 0;

	while (budget != 0 && i < ElementOfFile(f)) {


		if (Gioielli[i].prezzo <= budget) {
			budget -= Gioielli[i].prezzo;
			ris[j] = Gioielli[i];
			j++;
		}
		i++;
	}

	ris = realloc(ris, j * sizeof(Gioiello));

	*ret_size = j;


	free(Gioielli);
	free(appetibilita);

	return ris;
}