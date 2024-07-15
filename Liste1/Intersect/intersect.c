#include "list.h"
Item* Intersect(const Item* i1, const Item* i2) {


	Item* ris = ListCreateEmpty();

	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i)) {
		
		for (const Item* j = i2; !ListIsEmpty(j); j = ListGetTail(j)) {

			if (ElemCompare(ListGetHeadValue(i),ListGetHeadValue(j)) == 0) {

				ris = ListInsertBack(ris,ListGetHeadValue(i));
				break;

			}

		}
		
	}

	return ris;

}