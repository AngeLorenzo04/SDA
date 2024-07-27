#define _CRT_SERCURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

static void FrazioneEgiziaRec(double n, double d, int uni_d, int uni_n) {

	//calolo la funzione unitaria

	uni_d = ceil(d / n);
	printf("%d/%d", uni_n, uni_d);

	//caso base
	if ((int)d % (int)n == 0) {
		return;
	}

	printf(" + ");

	//calcola n e d
	n = uni_d * n - d;
	d = uni_d * d;
	FrazioneEgiziaRec(n, d, uni_d, uni_n);
	
}

void FrazioneEgizia(int n, int d) {

	
	if (n > d || n <= 0 || d <= 0) {
		printf("Impossibile convertire la frazione data in frazione egizia");
		return;
	}
	
	double n_ = n;
	double d_ = d;
	
	FrazioneEgiziaRec(n_, d_, 0, 1);

}