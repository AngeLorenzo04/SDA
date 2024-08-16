#include "list.h"
extern int ContaVette(const Item* i);


int main(void) {
	
	const Item* l = ListCreateEmpty();

	ElemType data[] = { 3, 2, 1, 4 };

	for (size_t i = 0; i < 4; i++) {

		l = ListInsertBack(l, data + i);

	}

	ContaVette(l);

	return 0;

}