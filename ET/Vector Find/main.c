#include "vettore.h"

int main(void) {

	srand(2);

	ElemType* data = calloc(10, sizeof(ElemType));

	for (size_t i = 0; i < 10; i++) {

		*(data + i) = rand() % 10;

	}

	Vector* v = malloc(sizeof(Vector));

	if (v != NULL) {
		v->size = 10;
		v->capacity = v->size * 2;
		v->data = data;
	}

	VectorFind(v, data + 3);

	return 0;
}