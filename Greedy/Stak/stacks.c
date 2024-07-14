#include "stacks.h"

static void Pop(Stack* stacks) {

	if (stacks->m > 0) {
		stacks->m--;
		/*
		* size_t nmem = --stacks->m;
		stacks->elements = realloc(stacks->elements, (nmem * sizeof(unsigned)));
		*/
	}


}

static bool SoluzioneTrovata(unsigned* sum, size_t n) {

	for (size_t i = 1; i < n; i++) {
		if (sum[i] != sum[i - 1]) {
			return false;
		}
	}

	return true;

}

static unsigned Min(unsigned* s, size_t n) {

	unsigned min = INT_MAX;

	for (size_t i = 0; i < n; i++) {
		if (s[i] < min) {
			min = s[i];
		}

	}

	return min;

}

static unsigned CalcolaSum(Stack s) {

	unsigned sum = 0;

	for (size_t i = 0; i < s.m; i++) {
		sum += s.elements[i];

	}

	return sum;

}

unsigned MaxSumNStack(Stack* stacks, size_t n) {

	unsigned* sum = calloc(n , sizeof(unsigned));
	for (size_t i = 0; i < n; i++) {

		sum[i] = CalcolaSum(stacks[i]);

	}

	unsigned min = 0;
	int tmp = -1;

	while (!SoluzioneTrovata(sum, n)) {

		min = Min(sum, n);
		for (int i = (tmp + 1); i < (int)n; i++) {

			if (sum[i] > min) {
				
				Pop(stacks + i);
				//aggiorna sum

				sum[i] = CalcolaSum(stacks[i]);

				if (i == (int)n - 1) {
					tmp = -1;
				}
				else {
					tmp = (int)i;
				}
				
				break;
			}
			if (i == (int)n - 1) {
				tmp = -1;
			}
		}

	}

	free(sum);

	return min;
}