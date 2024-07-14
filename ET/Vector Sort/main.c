#include "vettore.h"


int main(void) {

	srand(0);
	ElemType* data = calloc(10, sizeof(ElemType));
	
	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 10;
	}


	Vector* v = malloc(sizeof(Vector));

	if (v != NULL) {

		v->size = 10;
		v->capacity = v->size * 2;
		v->data = data;

	}

	VectorSort(v);

	return 0;
}