#include <stdbool.h>
#include <stdlib.h>
extern bool IsPalindromo(const char* str);

int main(void) {

	const char s1[] = "anna";
	const char s2[] = "";
	const char s3[] = "1";
	const char s4[] = "nonno";

	IsPalindromo(s1);
	IsPalindromo(s2);
	IsPalindromo(s3);
	IsPalindromo(s4);
	IsPalindromo(NULL);

	return 0;
}