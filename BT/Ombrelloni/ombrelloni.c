#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


static bool CheckValid(bool* vcurr, int i) {
	return(vcurr[i - 1] != vcurr[i]);
}

static void Print(bool* vcurr, int n, int* nsol) {
	printf("%d) ", *nsol);
	for (int m = 0; m < n - 1; m++) {
		printf("%d ", vcurr[m]);
	}
	printf("%d\n", vcurr[n - 1]);

}

static void OmbrelloniRec(int k, int n, int i, int cnt, int* nsol, bool* vcurr) {

	if (cnt == k) {
		(*nsol)++;
		Print(vcurr, n, nsol);
		return;
	}

	if (i == n) {
		return;
	}
	
	vcurr[i] = 1;
	if (i == 0 || CheckValid(vcurr,i)) {
		OmbrelloniRec(k, n, i + 1, cnt+1, nsol, vcurr);
	}
	
	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, cnt, nsol, vcurr);

	
}

int Ombrelloni(int k, int n) {
	
	if (k < 0 || n < 0) {
		return 0;
	}

	int nsol = 0;
	bool* vcurr = calloc(n, sizeof(bool));

	OmbrelloniRec(k, n, 0, 0, &nsol, vcurr);

	free(vcurr);

	return nsol;
}