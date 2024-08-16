#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static bool Valid(int* ris, size_t i,int e, const char* r) { //fase di parcing

	//verifico se il valore è già presente
	for (size_t j = 0; j < i; j++) {
		if (ris[j] == e && j != i) {
			return false;
		}
	}

	//se il valore precedente prevede un Decremetno, verificare che il valore che sto inserendo sia minore di quello precedente
	if (r[i - 1] == 'D') {
		return ris[i] < ris[i - 1];
	}

	//se il valore precedente prevede un Incremento, verificare che il valore che sto inderendo sia maggiore di quello precedente
	return ris[i] > ris[i - 1];
	
}

static void Print(int* ris, size_t size) { //Funzione per stampare le soluzioni

	for (size_t i = 0; i < size; i++) {
		printf("%d ", ris[i]);
	}

	printf("\n");

}

static void RegoleRec(const char* r, int* ris, size_t size, size_t i) { //funzione ricorsiva

	if (i == size) { //caso base
		Print(ris,size);
		return;
	}

	//esploro l'albero delle soluzioni ricorsivamente
	for (size_t j = 1; j <= size; j++) {
		ris[i] = j;
		if (i == 0 || Valid(ris, i, j, r)) {
			RegoleRec(r, ris, size, i + 1);
			ris[i] = -1;
		}
	}

}

void Regole(const char* r) {

	size_t n = strlen(r);

	if (n == 0) {
		printf("1");
		return;
	}
	
	int* ris = calloc(n + 1, sizeof(int)); //creo il vettore delle soluzioni

	RegoleRec(r, ris, n + 1, 0); //chiamo la funzione ricorsiva con gli argomenti che mi servono 

	free(ris);

	return;
}