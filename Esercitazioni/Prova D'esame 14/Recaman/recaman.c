#include <stdlib.h>

void RecamanRec(int n, int* vett, int i) {

	if (i == n) {
		return;
	}

	if (vett[i - 1] % i == 0) {
		vett[i] = vett[i - 1] / i;
	}
	else {
		vett[i] = vett[i - 1] * i;
	}

	RecamanRec(n, vett, i + 1);

}

int Recaman(int n) {

	if (n < 1) {
		return -1;
	}
	if (n == 1) {
		return 1;
	}

	int* vett = malloc(n * sizeof(int));
	vett[0] = 1;
	RecamanRec(n, vett, 1);

	return vett[n-1];
}