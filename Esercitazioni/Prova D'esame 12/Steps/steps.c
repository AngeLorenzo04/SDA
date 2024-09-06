#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isValid(int n, int e, int* sum) {

	return (e + *sum <= n);
}

void Print(int* vcurr, int n) {

	printf("[ ");

	for (int i = 0; i < n; i++) {
		if (vcurr[i] != 0) {
			printf("%d ", vcurr[i]);
		}
	}

	printf("]\n\n");
}

void StepsRec(int n, int i, int* nsol, int* sum, int* vcurr) {
	
	if (*sum == n) {
		(*nsol)++;
		Print(vcurr, n);
		return;
	}

	for (int j = 1; j < 4; ++j) {
		if (isValid(n, j, sum)) {
			vcurr[i] = j;
			*sum += j;
			StepsRec(n, i + 1, nsol, sum, vcurr);
			vcurr[i] = 0;
			*sum -= j;
		}
	}

}


int Steps(int n) {

	if (n <= 0) {
		return 0;
	}

	int* vcurr = calloc(n , sizeof(int));
	int sum = 0;
	int nsol = 0;
	StepsRec(n, 0, &nsol, &sum, vcurr);
	
	free(vcurr);

	return nsol;
}