#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern void ToUpper(char* str);

int main(void) {
	char* str = calloc(4,sizeof(char));
	char str1[] = "Ciao MoNdO!";
	strcpy(str, str1);
	ToUpper(str);
	printf("%s", str);
	return 0;
}