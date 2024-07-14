#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"


static size_t TrovaMigliore(Gioiello* g, size_t n) {

	float vbest = 0;
	size_t ibest = -1;

	for (size_t i = 0; i < n; ++i) {

		if (g[i].peso != 0) {
				
			float vcurr = g[i].peso / g[i].prezzo;
			
			if (ibest == -1 || vcurr > vbest) {

				vbest = vcurr;
				ibest = i;

			}

		}

	}

	return ibest;

}

static int LeggiDati(FILE* f, Gioiello** g) {

	Gioiello* letti = NULL;
	Gioiello tmp;

	size_t i = 0;

	while (1) {
		
		if (fscanf(f,"%i %f %f", &tmp.codice, &tmp.peso, &tmp.prezzo) != 3) {
			break;
		}

		letti = realloc(letti, (++i) * sizeof(Gioiello));
		letti[i - 1] = tmp;

	}

	*g = letti;

	return i;

}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {

	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return NULL;
	}


	Gioiello* g;
	int n = LeggiDati(f, &g);

	Gioiello* acquistati;
	acquistati = calloc(n, sizeof(Gioiello));

	*ret_size = 0;

	while (budget > 0) {

		size_t ibest = TrovaMigliore(g, n);
		if (ibest == -1) {
			break;
		}

		if (g[ibest].prezzo <= budget) {

			acquistati[(*ret_size)++] = g[ibest];
			budget -= g[ibest].prezzo;

		}

		g[ibest].peso = 0;

	}

	free(g);
	
	return acquistati;

}