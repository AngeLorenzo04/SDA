#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

static void IsBest(int* vcurr, int* vbest, int* sum, int* elem, int* topValore, int n, int k) {

	int sommaParallela = 0;
	*sum = 0;

	for (int i = 0; i < k; i++) {
		bool trovato = false;
		*sum += vcurr[i];
		for (int j = 0; j < n; j++) {
			if (elem[i] == vcurr[j]) {
				trovato = true;
			}
		}
		if (!trovato) {
			sommaParallela += elem[i];
		}
	}

	int novoValore = abs(*sum - sommaParallela);

	if (*topValore >= novoValore || *topValore < 0) {
		memcpy(vbest, vcurr, n * sizeof(int));
		*topValore = novoValore;
	}

}

static bool IsValid(int* vcurr,size_t n,int e) {

	for (size_t k = 0; k < n; k++) {

		if (vcurr[k] == e) {
			return false;
		}

		return true;

	}
}

static void Print(int* vcurr, size_t n, int check, int*elem, size_t k) {

	if (check == 0) {
		printf("{");


		for (int i = 0; i < n - 2; i++) {
			if (vcurr[i] != 0) {
				printf(" %d,", vcurr[i]);
			}
		}

		printf(" %d }, ", vcurr[n - 1]);

		printf("{");
		for (int i = 0; i < k-1; i++) {
			bool trovato = false;
			for (int j = 0; j < k / 2; j++) {
				if (elem[i] == vcurr[j]) {
					trovato = true;
				}
			}
			if (!trovato) {
				if (elem[i] != 0) {
					printf(" %d", elem[i]);
				}
				if (i != k - 2) {
					printf(",");
				}
			}


		}
		printf(" }");
	}
	else {
		printf("{ }, { }");
	}
}
static void TiroAllaFuneRec(int* vcurr, int* vbest, size_t i, size_t n, size_t k, int* elem, int* sum, int* topValore) {

	if (i == n) {
		IsBest(vcurr, vbest, sum, elem,topValore,n,k);
		
		return;
	}

	for (size_t l = 0; l < k; l++) {

		if (IsValid(vcurr, n,elem[l])) {
			vcurr[i] = elem[l];
			TiroAllaFuneRec(vcurr, vbest, i + 1, n, k, elem, sum, topValore);
		}

	}
	
}

int main(int argc, char* argv[]) {
	
	char* endptr;
	int* elem = calloc(argc - 1, sizeof(int));
	size_t j = 0;

	for (int i = 1; i < argc; i++) {
		elem[j] = strtol(argv[i], &endptr, 10);
		if (&endptr == NULL) {
			return 1;
		}
		j++;
	}

	int* vcurr = calloc(argc - 1, sizeof(size_t));
	int* vbest = calloc(argc - 1, sizeof(size_t));
	int sum = 0;
	int topValore = -1;
	TiroAllaFuneRec(vcurr, vbest, 0, (argc - 1)/2,argc - 1, elem, &sum, &topValore);
	Print(vbest, (argc - 1), 0, elem, (argc - 1 / 2));

	free(elem);
	free(vcurr);
	free(vbest);

}