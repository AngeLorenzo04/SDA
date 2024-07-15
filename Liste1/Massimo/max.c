#include "list.h"
#include <stdlib.h>
const ElemType* MaxElement(const Item* i) {

	ElemType* max = calloc(1,sizeof(ElemType));

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		if (ElemCompare(ListGetHeadValue(tmp), max) > 0) {
			max = ListGetHeadValue(tmp);
		}

	}

	return max;

}