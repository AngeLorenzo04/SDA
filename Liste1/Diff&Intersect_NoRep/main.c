#include "list.h"

extern Item* IntersectNoRep(const Item* i1, const Item* i2);
extern Item* DiffNoRep(const Item* i1, const Item* i2);

int main(void) {

	ElemType data1[8] = { 1, 3, 4, 2, 0, 45, 2, 1 };
	ElemType data2[8] = { 45, 8, 5, 2, 3, 45, 7, 5 };


	Item* i1 = ListCreateEmpty();
	Item* i2 = ListCreateEmpty();

	for (size_t i = 0; i < 8; i++) {

		i1 = ListInsertBack(i1, data1 + i);

	}
	for (size_t i = 0; i < 8; i++) {

		i2 = ListInsertBack(i2, data2  + i);

	}


	printf("list: ");
	ListWriteStdout(i1);
	printf("\n\n");
	ListWriteStdout(i2);
	printf("\n\n");
	printf("intersection: ");
	ListWriteStdout(IntersectNoRep(i1, i2));
	printf("\n\ndifferenza: ");
	ListWriteStdout(DiffNoRep(i1, i2));

	return 0;
}