#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void SubsetKRec(int n, int k, bool* vcurr, int* nsol, int i) {

	if (i == n) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (vcurr[j] == 1) {
				cnt++;
				printf("%d, ", j);
			}

		}

		if (cnt == k) {
			*nsol++;
			printf("}, ");

		}

		return;
	}

	vcurr[i] = 0;
	SubsetKRec(n, k, vcurr, nsol, i + 1);

	vcurr[i] = 1;
	SubsetKRec(n, k, vcurr, nsol, i + 1);
	
}

int SubsetK(int n, int k) {
	int nsol = 0;
	bool* vcurr = malloc(n * sizeof(bool));

	SubsetKRec(n, k, vcurr, &nsol, 0);

	free(vcurr);
	return;
}


int main(void) {
	SubsetK(4, 2);
	return 0;
}