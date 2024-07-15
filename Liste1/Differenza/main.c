#include "list.h"
extern Item* Diff(const Item* i1, const Item* i2);


int main(void) {

	ElemType data1[7] = { 1, 45, 0, 2, 4, 1, 3 };
	ElemType data2[6] = { 7, 45, 3, 2, 5 };

	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	for (size_t i = 0; i < 7; i++) {

		i1 = ListInsertBack(i1, data1 + i);

	}
	for (size_t i = 0; i < 6; i++) {

		i2 = ListInsertBack(i2, data2 + i);

	}


	Diff(i1, i2);

	return 0;

}
