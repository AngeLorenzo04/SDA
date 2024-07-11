#include<stdlib.h>
extern int ContaOccorrenze(const char* filename, const char* str);


int main(void) {
	int ris = ContaOccorrenze("file3.txt", "sborra");
	return 0;
}