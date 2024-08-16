#include "list.h"
extern Item* CopiaDaN(const Item* i, int n);


int main(void) {

	Item* l  = ListCreateEmpty();


	int e[] = { 12,2,37,4 };

	for (size_t i = 0; i < 4; i++) {

		l = ListInsertBack(l, e + i);

	}

	l = CopiaDaN(l, 2);

	return 0;
}