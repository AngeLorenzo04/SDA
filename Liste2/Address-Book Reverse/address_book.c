#include "list.h"

Item* Reverse(const Item* i) {

	Item* ris = ListCreateEmpty();

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		ris = ListInsertHead(ListGetHeadValue(tmp), ris);

	}

	return ris;

}