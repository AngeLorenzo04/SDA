#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

Item* AppendMod(Item* i1,  Item* i2) {

	if (i1 == NULL) {
		return i2;
	}

	Item* tmp = i1;

	while (1) {

		tmp = ListGetTail(tmp);
		if (tmp->next == NULL) {
			break;
		}
	}

	tmp->next = i2;
	

	return i1;

}