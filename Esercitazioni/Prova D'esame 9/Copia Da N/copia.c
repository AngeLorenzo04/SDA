#include "list.h"


static size_t ListSize(const Item* i) {

	size_t size = 0;

	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		size++;
	}

	return size;
}

Item* CopiaDaN(const Item* i, int n) {

	Item* ris = ListCreateEmpty();

	if (ListIsEmpty(i) || n > (int)ListSize(i)) {
		return ris;
	}

	
	size_t j = 0;
	while ((int)j != n - 1) {

		i = ListGetTail(i);
		j++;
		
	}
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		ris = ListInsertBack(ris, ListGetHeadValue(i));
	}
	return ris;

}
