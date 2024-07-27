#include "list.h"

extern Item* CreaDaMinori(const Item* i, int v);


int main(void) {

	const Item* list = ListCreateEmpty();

	ElemType data[5] = { 2,3,4,1,9 };

	for (size_t i = 0; i < 5; i++) {

		list = ListInsertBack(list, data + i);

	}

	list = CreaDaMinori(list, 5);

	return 0;
}