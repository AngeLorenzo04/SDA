#include "list.h"
int ContaVette(const Item* i) {

	int ris = 0;

	for (; !ListIsEmpty(i); i = ListGetTail(i)) {

		bool isvetta = true;
		Item* j = ListGetTail(i);

		for (; !ListIsEmpty(j); j = ListGetTail(j)) {

			if (ElemCompare(ListGetHeadValue(i), ListGetHeadValue(j)) < 0) {
				isvetta = false;
				break;
			}
			
		}

		if (isvetta) {
			ris++;
		}
		
	}

	return ris;

}