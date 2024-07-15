#include "list.h"
Item* ListLoad(const char* filename) {

	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return NULL;
	}

	Item* l = ListCreateEmpty();

	ElemType tmp;

	while (ElemRead(f,&tmp) == 1) {

		l = ListInsertHead(&tmp, l);

	}

	ListWriteStdout(l);
	fclose(f);
	return l;
}