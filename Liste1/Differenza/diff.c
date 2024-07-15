#include "list.h"

Item* Diff(const Item* i1, const Item* i2) {

	Item* ris = ListCreateEmpty();

	

	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i)) {
		
		bool trovato = false;
		
		for (const Item* j = i2; !ListIsEmpty(j); j = ListGetTail(j)) {

			if (ElemCompare(ListGetHeadValue(i), ListGetHeadValue(j)) == 0) {
				trovato = true;
				break;
			}


		}
		if (!trovato) {
			ris = ListInsertBack(ris, ListGetHeadValue(i));
		}
			
	}

	ListWriteStdout(ris);

	return ris;

}