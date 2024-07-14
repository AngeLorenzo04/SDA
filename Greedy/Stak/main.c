#include "stacks.h"

int main(void) {

	unsigned* data1 = malloc(4 * sizeof(unsigned));

	data1[0] = 7;
	data1[1] = 6; 
	data1[2] = 9;
	data1[3] = 5;

	unsigned* data2 = malloc(4 * sizeof(unsigned));

	data2[0] = 3;
	data2[1] = 4;
	data2[2] = 1;
	data2[3] = 9;

	unsigned* data3 = malloc(4 * sizeof(unsigned));

	data3[0] = 2;
	data3[1] = 2;
	data3[2] = 3;
	data3[3] = 8;

	Stack s[3] = { {data1,4}, {data2,4}, {data3,4} };

	printf("ris: %d",MaxSumNStack(s, 3));

	

	return 0;
};


/*{{1, 1, 1, 2, 3}, {2, 3, 4}, {1, 4, 5, 2}};*/