#define _CRT_SECURE_NO_WARNINGS
#include "vettore.h"

static int compare(const void* a, const void* b) {
	return (*(ElemType*)a - *(ElemType*)b);
}

static size_t NumElem(FILE* f) {

	int readcntrl = 1;
	ElemType tmp;
	size_t dim = 0;
	while (readcntrl > 0) {
		readcntrl = ElemRead(f, &tmp);
		dim++;
	}
	rewind(f);
	dim--;

	return dim;
}

Vector* VectorRead(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Vector *v = calloc(1, sizeof(Vector));

	if (v != NULL) {

		v->capacity = 2 * NumElem(f);
		v->size = NumElem(f);
		v->data = malloc(v->size * sizeof(ElemType));

	}


	for (size_t i = 0; v != NULL && i < v->size; i++) {

		ElemRead(f, v->data + i);

	}
	fclose(f);

	return v;

}
Vector* VectorReadSorted(const char* filename) {



	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Vector* v = calloc(1, sizeof(Vector));

	if (v != NULL) {

		v->capacity = 2 * NumElem(f);
		v->size = NumElem(f);
		v->data = malloc(v->size * sizeof(ElemType));

	}


	for (size_t i = 0; v != NULL && i < v->size; i++) {

		ElemRead(f, v->data + i);

	}

	
	if (v != NULL) {

		qsort(v->data, v->size , sizeof(ElemType),compare);

	}


	fclose(f);

	return v;

}