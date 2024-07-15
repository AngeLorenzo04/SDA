#define _CRT_SECURE_NO_WARNINGS

#include "list.h"
#include <stdlib.h>
extern Item* Delete(Item* i, const char* name) {

	Item ricercato;
	strcpy(ricercato.value.name, name);
	Item* prev = NULL;

	for (Item* corrente = i; !ListIsEmpty(corrente); corrente = ListGetTail(corrente)) {

		if (ElemCompare(ListGetHeadValue(corrente), ListGetHeadValue(&ricercato)) == 0) {

			if (prev == NULL) {

				i = ListGetTail(i);

			}
			else {

				prev->next = corrente->next;
				ElemDelete(ListGetHeadValue(corrente));
			}
			
			return i;
		}

		prev = corrente;

	}


	return i;

}