#include "list.h"
extern Item* Intersect(const Item* i1, const Item* i2);

int main(void) {

	ElemType data1[7] = { 3, 4, 2, 0, 45, 1, 3 };
	ElemType data2[6] = { 8, 5, 2, 3, 45, 7 };

	Item* l1 = ListCreateEmpty();
	Item* l2 = ListCreateEmpty();

	for (size_t i = 0; i < 7; i++) {
		l1 = ListInsertBack(l1, data1 + i);
	}
	for (size_t i = 0; i < 6; i++) {
		l2 = ListInsertBack(l2, data2 + i);
	}

	Intersect(l1, l2);

	return 0;
}