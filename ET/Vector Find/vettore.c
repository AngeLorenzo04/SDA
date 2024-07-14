#include "vettore.h"

int VectorFind(const Vector* v, const ElemType* e){

	if (v != NULL && e != NULL) {

		for (size_t i = 0; i < v->size; i++) {
			if (*(v->data + i) == *e) {
				return (int)i;
			}
		}
	}

	return -1;



}