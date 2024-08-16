#include "colori.h"

int main(void) {
	
	struct Matrix* m = malloc(sizeof(struct Matrix));

	bool data[] = { 1,1,1,1,1,0,1,0,1 };

	m->data = malloc(6 * sizeof(bool));

	m->data = data;

	m->size = 3;

	const char c[] = { 'r','v' };

	MappaColori(m, c, 2);

	return 0;
}