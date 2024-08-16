#include <stdlib.h>
extern void InsertionSort(int* v, size_t v_size);

int main(void) {


	size_t v_size = 2;
	int* v = malloc(v_size * sizeof(int));
	int data[] = { 5,3 };

	for (size_t i = 0; i < v_size; i++) {
		v[i] = data[i];
	}

	InsertionSort(v, v_size);

	return 0;
}