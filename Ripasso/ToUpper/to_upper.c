#include <string.h>

void ToUpper(char* str) {

	if (str != NULL) 
	{
		for (size_t i = 0; i < strlen(str); i++) {

			if (*(str + i) >= 97 && *(str + i) <= 123) {
				*(str + i) -= 32;
			}
		}
	}

}