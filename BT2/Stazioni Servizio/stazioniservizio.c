#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

static void IsBest(size_t n, size_t* vbest, size_t* vcurr, double *sommaprezzo , double *meglioprezzo) {

	if (*sommaprezzo < *meglioprezzo) {
		
		memcpy(vbest, vcurr, n * sizeof(size_t));
		*meglioprezzo = *sommaprezzo;
	}

}

static void Print(size_t n, size_t* vbest, double kmPercorsi) {
	for (size_t k = 0; k < n; k++) {
		if (vbest[k] != 0) {
			printf("%zu ", vbest[k] - 1);
		}
	}
	printf("\n");
	printf("melgioprezzo: %f euro", kmPercorsi);
	return;
}

static bool validSoluzione(size_t* vcurr, size_t n,double m, double*maxKm, const double* d , double* kmPercorsi) {

	size_t stazpiudist = 0;
	double calckmPercorsi = 0;

	for (size_t k = 0; k < n; k++) {

		if (stazpiudist < vcurr[k]) {
			stazpiudist = vcurr[k];
		}

	}

	for (size_t k = 0; k < (size_t)stazpiudist; k++) {
			calckmPercorsi += d[k];
	}

	if (calckmPercorsi + *maxKm < m) {
		return false;
	}

	*kmPercorsi = calckmPercorsi;
	return true;
}

static bool validPercorso(size_t j, size_t n, size_t *vcurr, double* maxKm, const double* d) {

	for (size_t k = 0; k < n; k++) {
		if (vcurr[k] >= j) {  //non posso andare 2 volte nella stessa stazione e non posso tonrare in dietro
			return false;
		}
	}

	if (*maxKm < d[j - 1]) {  //posso arrivarci?
		return false;
	}


	return true;
}

static bool ValidStazione(size_t n, size_t j, size_t i, size_t* vcurr) {

	if (vcurr[i - 1] == 0) { //non posso avere cose del tipo 1, 0, 2, più tosto 1, 2
		return false;
	}

	for (size_t k = 0; k < n; k++) {
		if (vcurr[k] >= j) {  //non posso andare 2 volte nella stessa stazione e non posso tonrare in dietro
			return false;
		}
	}
	return true;

}

static void StazioniServizioRec(double m, const double* d, const double* p, size_t n, size_t i, 
	double *maxKm, double *kmPercorsi ,double* sumprezzo, double* meglioprezzo,size_t* vcurr, size_t* vbest) {

	double tmp;
	double tmp1;

	if (n == i) {

		
		if (validSoluzione(vcurr, n, m, maxKm, d, kmPercorsi)) {
			IsBest(n, vbest, vcurr, sumprezzo, meglioprezzo);
		}

		return;
		
	}

	for (size_t j = 1; j < n; j++) {
		
		if (validPercorso(j, n, vcurr, maxKm, d)) {

			*maxKm -= d[j-1]; //consuma km

			if (ValidStazione(n, j, i, vcurr)) {
				vcurr[i] = j;
				tmp1 = *sumprezzo;
				*sumprezzo += p[j-1] * (600 - *maxKm) * 0.05;
				tmp = *maxKm;
				*maxKm = 600;
				StazioniServizioRec(m, d, p, n, i + 1, maxKm, kmPercorsi, sumprezzo, meglioprezzo, vcurr, vbest);
				vcurr[i] = 0;
				*sumprezzo = tmp1;
				*maxKm = tmp;
			}
		}
	}

	if(i != 0){
		vcurr[i] = 0;
		StazioniServizioRec(m, d, p, n, i + 1, maxKm, kmPercorsi, sumprezzo, meglioprezzo,vcurr, vbest);

	}

}
void StazioniServizio(double m, const double* d, const double* p, size_t n) {
	size_t* vcurr = calloc(n, sizeof(size_t));
	size_t* vbest = calloc(n, sizeof(size_t));
	double kmPercorsi = 0;
	double sumprezzo = 0;
	double meglioprezzo = INT_MAX;
	double maxKm = 600;
	StazioniServizioRec(m, d, p, n,0, &maxKm, &kmPercorsi, &sumprezzo,&meglioprezzo, vcurr, vbest);

	// controlla che vbest non sia vuoto
	size_t cnt = 0;
	for (size_t k = 0; k < n; k++) {
		if (vbest[k] == 0) {
			cnt++;
		}
	}

	if (cnt == n) {
		printf("non ci sono soluzioni");
	}
	else {
		Print(n,vbest, meglioprezzo);
	}

	free(vbest);
	free(vcurr);
}