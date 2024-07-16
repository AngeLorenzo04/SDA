#include "list.h"
static size_t LenList(Item* i) {
	size_t len = 0;
	while (!ListIsEmpty(i)) {
		i = ListGetTail(i);
		len++;
	}

	return len;

}

Item* Sort(Item* i) {

    Item* head = i; 

	bool done = false;
	size_t dim = LenList(i);

	if (dim == 1) {
		return i;
	}

	while (!done) {
		done = true;
		Item* curr = head;
		Item* prev = NULL;
		
		for (size_t j = 0; j < dim; j++) {

			Item* fol = curr->next;
			Item* folfol = fol->next;

			if (ElemCompare(ListGetHeadValue(curr), ListGetHeadValue(fol)) > 0) {

				if (prev == NULL) {

					head = fol;

					curr->next = folfol;
					fol->next = curr;

				}
				else {

					prev->next = fol;
					curr->next = folfol; 
					fol->next = curr;

				}
				
				prev = fol;
				done = false;

			}

			prev = curr;
			curr = fol;

		}

		dim--;

	}

	return head;
}