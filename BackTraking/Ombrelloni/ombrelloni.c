#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void Print(bool* vcurr, int n, int *nsol) {
	printf("%4d) ", *nsol);
	for (int m = 0; m < n - 1; m++) {
			printf("%d ", vcurr[m]);
	}
	printf("%d\n", vcurr[n - 1]);

}


bool ChekPos(bool* vcurr, int i) {

	return !(vcurr[i] == 1 && vcurr[i - 1] == 1);
	

}

void OmbrelloniRec(int k, int n, int i, bool* vcurr, int* nsol, int cnt) {

	if (cnt == k) {
		(*nsol)++;
		Print(vcurr, n, nsol);
		return;
	}

	if (i == n) { //Sempre
		return;
	}

	vcurr[i] = 1;
	if (i == 0 || ChekPos(vcurr,i)) {
		OmbrelloniRec(k, n, i + 1, vcurr, nsol, cnt + 1);
	}
	

	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol, cnt);


}

int Ombrelloni(int k, int n) {
	
	if (k < 0 || n < 0) {
		return 0;
	}

	if (n % 2 == 0) {
		if (k > n / 2) {
			return 0;
		}
	}
	else {
		if (k > (n / 2) + 1) {
			return 0;
		}
	}

	int nsol = 0;
	bool* vcurr = calloc(n , sizeof(bool));

	OmbrelloniRec(k, n, 0, vcurr, &nsol, 0);

	return nsol;
}
/*

			____

*/