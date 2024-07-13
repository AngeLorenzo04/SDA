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

static bool IsValid(int* vcurr,int n,int e) {

	for (int k = 0; k < n; k++) {

		if (vcurr[k] == e) {
			return false;
		}		

	}
	return true;
}

static void Print(int* vcurr, int n, int check, int* elem, int k) {
	
	bool trovato = false;
	int* vett2 = calloc(k, sizeof(int));
	int l = 0;

	for (int i = 0; i < k; i++) {
		trovato = false;
		for (int j = 0; j < n; j++) {
			if (elem[i] == vcurr[j]) {
				trovato = true;
			}
		}
		if (!trovato) {
			vett2[l] = elem[i];
			l++;
		}
	}
	
	printf("{ ");
	for (int i = 0; i < n; i++) {

		if (i == n - 1) {
			printf("%d", vcurr[i]);
		}
		else {
			printf("%d, ", vcurr[i]);
		}

	}
	printf(" }, ");

	printf("{ ");
	for (int i = 0; i < n + check; i++) {

		if (i == (n + check) - 1) {
			printf("%d", vett2[i]);
		}
		else {
			printf("%d, ", vett2[i]);
		}

	}
	printf(" }");


	

}
static void TiroAllaFuneRec(int* vcurr, int* vbest, int i, int n, int k, int* elem, int* sum, int* topValore) {

	if (i == n) {
		IsBest(vcurr, vbest, sum, elem,topValore,n,k);
		
		return;
	}

	for (int l = 0; l < k; l++) {

		if (IsValid(vcurr, n,elem[l])) {
			vcurr[i] = elem[l];
			TiroAllaFuneRec(vcurr, vbest, i + 1, n, k, elem, sum, topValore);
		}

	}
	
}

int main(int argc, char* argv[]) {
	
	char* endptr;
	int* elem = calloc(argc - 1, sizeof(int));
	int j = 0;

	for (int i = 1; i < argc; i++) {
		elem[j] = strtol(argv[i], &endptr, 10);
		if (&endptr == NULL) {
			return 1;
		}
		j++;
	}

	int* vcurr = calloc(argc - 1, sizeof(int));

	int* vbest = calloc(argc - 1, sizeof(int));

	int sum = 0;
	int topValore = -1;
	TiroAllaFuneRec(vcurr, vbest, 0, (argc - 1)/2,argc - 1, elem, &sum, &topValore);
	if ((argc - 1) % 2 == 0) {
		Print(vbest, (argc - 1) / 2, 0, elem, (argc - 1));
	}
	else {
		Print(vbest, (argc - 1) / 2, 1, elem, (argc - 1));
	}

	free(elem);
	free(vcurr);
	free(vbest);

}