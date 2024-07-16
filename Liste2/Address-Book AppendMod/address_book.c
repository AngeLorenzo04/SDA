#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Item* AppendMod(Item* i1,  Item* i2) {


	for (Item* tmp = i2; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		i1 = ListInsertBack(i1, ListGetHeadValue(tmp));

	}

	return i1;

}