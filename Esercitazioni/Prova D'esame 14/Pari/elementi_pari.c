#include "list.h"
Item* ElementiPari(const Item* i) {

	Item* ris = ListCreateEmpty();
	Item* tmp = i;

	size_t j = 2;
	for (; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (j % 2 == 0) {
			ris = ListInsertBack(ris,ListGetHeadValue(tmp));
		}

		j++;
	}

	return ris;
}