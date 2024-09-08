#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct arr {
	int* data;
	int size;
};

void Print(int n, int* vcurr) {
	printf("{");
	for (int i = 0; i < n; i++) {
		if (vcurr[i] != 0) {
			printf("%d ", vcurr[i]);
		}
	}
	printf("} ");
}

bool IsValid(int* sum, int s) {
	return (s >= *sum);
}

bool IsNPresent(int n, int j, int i, int* vcurr) {
	for (int k = 0; k < n; k++) {
		if (vcurr[k] == j && k != i) {
			return false;
		}
	}

	return true;
}

//bool CheckSoluzioni(struct arr* soluzioni, int* vett, int n, bool primogiro) {
//
//	if (primogiro) {
//		return true;
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (vett[j] != soluzioni->data) {
//				return true;
//			}
//		}
//	}
//
//	return false;
//}
//
//void FillSoluzioni(struct arr* soluzioni, int* vett, int i, int n) {
//	soluzioni[i].size = n;
//	soluzioni[i].data = malloc(n * sizeof(int));
//	soluzioni[i].data = vett;
//}

void SubSetEqualRec(int n, int s, int i, int* vcurr, int* sum /*struct arr* soluzioni, bool* primogiro*/) {

	if (*sum == s) {
		/*if (CheckSoluzioni(soluzioni,vcurr,n,*primogiro)) {
			*primogiro = false;
			FillSoluzioni(soluzioni, vcurr, i, n);*/
			Print(n, vcurr);
		/*}*/
		return;
	}


	for (int j = 1; j <= n; ++j) {
		vcurr[i] = j;
		*sum += j;
		if (IsValid(sum, s) && IsNPresent(n, j, i, vcurr)) {
			SubSetEqualRec(n, s, i + 1, vcurr, sum /*soluzioni, primogiro*/);
		}
		vcurr[i] = 0;
		*sum -= j;
	}
	
}

void SubsetEqual(int n, int s) {

	int* vcurr = calloc(n, sizeof(int));
	int sum = 0;
	//struct arr* soluzioni = malloc(n * sizeof(struct arr));
	//bool primogiro = true;
	SubSetEqualRec(n, s, 0, vcurr, &sum/* soluzioni,&primogiro*/);

}