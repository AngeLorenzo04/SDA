#include "list.h"
extern const ElemType* MaxElement(const Item* i);

int main(void) {
	
	const ElemType data[5] = { 3,8,3000000,1,10 };

	const Item* i = ListCreateEmpty();

	for (size_t t = 0; t < 5; t++) {

		i = ListInsertBack(i, data + t);

	}

	

	printf("list: ");
	ListWriteStdout(i);
	printf("\nmax elem: %i", *MaxElement(i));

	return 0;

}