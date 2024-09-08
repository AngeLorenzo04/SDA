#include "list.h"
extern Item* ElementiPari(const Item* i);
//crea due liste di ElemType: 
//				  i1 = 1, 45 , 0, 2, 4, 1, 3 
//				  i2 = 7, 45 , 3, 2, 5, 

int main(void) {

	ElemType data1[7] = { 1, 45, 0, 2, 4, 1, 3 };

	const Item* i1 = ListCreateEmpty();

	for (size_t i = 0; i < 7; i++) {

		i1 = ListInsertBack(i1, data1 + i);

	}

	ListWriteStdout(i1);


	i1 = ElementiPari(i1);

	ListWriteStdout(i1);

	return 0;
}