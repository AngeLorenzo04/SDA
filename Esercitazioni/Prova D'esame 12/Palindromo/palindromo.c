#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void IsPalindromoRec(const char* str, size_t len, size_t i, bool* ris) {
	

	if (i == len) {
		return;
	}

	if (str[i] != str[len - i - 1]) {
		*ris = false;
		return;
	}

	IsPalindromoRec(str, len, i + 1, ris);
}

bool IsPalindromo(const char* str) {
	
	if (str == NULL) {
		return false;
	}

	size_t len = strlen(str);
	bool ris = true;

	IsPalindromoRec(str, len, 0, &ris);

	return ris;

}
