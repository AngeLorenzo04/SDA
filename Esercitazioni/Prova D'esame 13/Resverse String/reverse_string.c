#include <stdlib.h>
#include <string.h>
void ReverseStringRec(const char* str, size_t len, size_t i, char* ris) {

	if (len == 0) {
		ris[i] = 0;
		return;
	}

	ris[i] = str[len - 1];

	ReverseStringRec(str, len - 1, i + 1, ris);

}

char* ReverseString(const char* str) {

	if (str == NULL) {
		return NULL;
	}

	size_t len = strlen(str);

	char* ris = calloc(len,sizeof(char));

	ReverseStringRec(str, len, 0, ris);

	return ris;
}