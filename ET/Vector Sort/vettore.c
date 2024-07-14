#include "vettore.h"


void VectorSort(Vector* v) {

	if (v == NULL) {
		return;
	}

	for (size_t i = 0; i < v->size; i++) {

		ElemType *min = v->data + i;

		for (size_t j = i + 1; j < v->size; j++) {
			
			if (ElemCompare(min, v->data + j) > 0) {

				min = v->data + j;

			}

		}

		ElemSwap(v->data + i, min);


	}




}