
#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Item* Filtra(const Item* i, const char* city) {

	Item ricercato;
	strcpy(ricercato.value.city, city);

	Item* ris = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		if (ElemCompare(ListGetHeadValue(tmp),ListGetHeadValue(&ricercato)) == 0){

			ris = ListInsertBack(ris,ListGetHeadValue(tmp));

		}

	}

	return ris;

}