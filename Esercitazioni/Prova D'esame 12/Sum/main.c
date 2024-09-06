#include "list.h"

extern Item* Sum(const Item* i1, const Item* i2);
int main(void) {

	ElemType data1[3] = { 3,2,4 };
	ElemType data2[1] = { 7 };

	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	for (size_t i = 0; i < 3; i++) {

		i2 = ListInsertBack(i1, data1 + i);

	}
	for (size_t i = 0; i < 1; i++) {

		i1 = ListInsertBack(i2, data2 + i);

	}

	ListWriteStdout(Sum(i1, i2));


	return 0;
}