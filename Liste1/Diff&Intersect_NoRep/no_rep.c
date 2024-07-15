#include "list.h"


static bool Presente(const ElemType* e, Item* i) {

	for (const Item* tmp = i;  !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(e, ListGetHeadValue(tmp)) == 0) {
			return true;
		}

	}

	return false;

}

Item* IntersectNoRep(const Item* i1, const Item* i2) {

	Item* ris = ListCreateEmpty();

	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i)) {
		for (const Item* j = i2; !ListIsEmpty(j); j = ListGetTail(j)) {

			if (!Presente(ListGetHeadValue(i), ris) && ElemCompare(ListGetHeadValue(i), ListGetHeadValue(j)) == 0) {
				ris = ListInsertBack(ris,ListGetHeadValue(i));
				break;
			}

		}
	}

	return ris;
}
Item* DiffNoRep(const Item* i1, const Item* i2) {


	Item* ris = ListCreateEmpty();



	for (const Item* i = i1; !ListIsEmpty(i); i = ListGetTail(i)) {

		bool trovato = false;

		for (const Item* j = i2; !ListIsEmpty(j); j = ListGetTail(j)) {

			if (ElemCompare(ListGetHeadValue(i), ListGetHeadValue(j)) == 0) {
				trovato = true;
				break;
			}

		}
		if (!Presente(ListGetHeadValue(i), ris) && (!trovato)) {
			ris = ListInsertBack(ris, ListGetHeadValue(i));
		}
	}

	return ris;

}