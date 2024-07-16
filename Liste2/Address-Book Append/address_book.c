
#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Item* Append(const Item* i1, const Item* i2) {

	const Item* ris = i1;

	for (const Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		ris = ListInsertBack(ris, ListGetHeadValue(tmp));

	}

	return ris;

}