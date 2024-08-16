extern int AToI(const char* str);
#include <stdio.h>

int main(void) {
	printf("%d\n", AToI("-1234"));
	printf("%d\n", AToI("1234"));
	printf("%d\n", AToI("12 34"));
	printf("%d\n", AToI("12a34"));
	return 0;
}