#include "list.h"
extern Item* Append(const Item* i1, const Item* i2);

int main(void) {
	
	ElemType inidrizzi[5] = { 

		{"Angelo","Via Moneta",23,"Laterza","TA","74014"},
		{"Antonio","Via Montenero",3,"Matera","MA","39232"},
		{"Marco","Via Montenero",3,"Matera","MA","39232"},
		{"Francesco","Via Montenero",3,"Matera","MA","39232"},
		{"Michele","via G.B. Vico",9,"Ginosa","TA","23439"}
	};

	ElemType inidrizzi2[5] = {

		{"Simone","Via Moneta",23,"Laterza","TA","74014"},
		{"Luca","Via Montenero",3,"Matera","MA","39232"},
		{"Leonardo","Via Montenero",3,"Matera","MA","39232"},
		{"Mimmo","Via Montenero",3,"Matera","MA","39232"},
		{"Dino","via G.B. Vico",9,"Ginosa","TA","23439"}
	};
	
	
	
	const Item* i1 = ListCreateEmpty();

	for (size_t j = 0; j < 5; j++) {

		i1 = ListInsertBack(i1, inidrizzi + j);

	}
	const Item* i2 = ListCreateEmpty();

	/*for (size_t j = 0; j < 5; j++) {

		i2 = ListInsertBack(i2, inidrizzi2 + j);

	}*/
	
	ListWriteStdout(i1);
	ListWriteStdout(i2);
	
	printf("\n");
	ListWriteStdout(Append(i1,i2));
	
	
	return 0;

}