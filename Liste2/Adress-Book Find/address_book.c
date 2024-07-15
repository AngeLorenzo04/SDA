#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

const ElemType* Find(const Item* i, const char* name) {

	Item ricercato;
	strcpy(ricercato.value.name, name);

	if (i == NULL || name == NULL) {
		return NULL;
	}

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		//if (strcmp(ListGetHeadValue(tmp)->name, name) == 0) {
		//	return ListGetHeadValue(tmp);
		//}

		if (ElemCompare(ListGetHeadValue(tmp), ListGetHeadValue(&ricercato)) == 0) {
			return ListGetHeadValue(tmp);
		}


	}

	return NULL;

}