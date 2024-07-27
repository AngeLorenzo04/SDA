#include "list.h"


Item* CreaDaMinori(const Item* i, int v) {

	Item* ris = ListCreateEmpty();

	for (; !ListIsEmpty(i); i = ListGetTail(i)) {

		if (ElemCompare(ListGetHeadValue(i), &v) < 0) {

			ris = ListInsertBack(ris, ListGetHeadValue(i));

		}
	}

	return ris;
}