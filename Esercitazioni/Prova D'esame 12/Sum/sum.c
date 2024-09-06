#include "list.h"
#include <stdbool.h>
size_t ListLen(const Item* i1) {
	size_t len = 0;
	for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
		len++;
	}
	return len;
}

Item* Sum(const Item* i1, const Item* i2) {

	Item* ris = ListCreateEmpty();

	bool carry = false;

	if (ListLen(i1) > ListLen(i2)) {
		
		for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
			if (!ListIsEmpty(i2)) {
				ElemType e = *ListGetHeadValue(i1) + *ListGetHeadValue(i2);
				if (carry) {
					e++;
					carry = false;
				}
				if (e >= 10) {
					e -= 10;
					carry = true;
				}
				const ElemType tmp = e;
				ris = ListInsertBack(ris, &tmp);

				if (!ListIsEmpty(i2)) {
					i2 = ListGetTail(i2);
				}
			}
			else {
				ElemType e = *ListGetHeadValue(i1);
				if (carry) {
					e++;
					carry = false;
				}
				if (e >= 10) {
					e -= 10;
					carry = true;
				}
				const ElemType tmp = e;
				ris = ListInsertBack(ris, &tmp);
			}

		}
	}
	else {

		for (; !ListIsEmpty(i2); i2 = ListGetTail(i2)) {
			if (!ListIsEmpty(i1)) {
				ElemType e = *ListGetHeadValue(i1) + *ListGetHeadValue(i2);
				if (carry) {
					e++;
					carry = false;
				}
				if (e >= 10) {
					e -= 10;
					carry = true;
				}
				const ElemType tmp = e;
				ris = ListInsertBack(ris, &tmp);

				if (!ListIsEmpty(i1)) {
					i1 = ListGetTail(i1);
				}
			}
			else {
				ElemType e = *ListGetHeadValue(i2);
				if (carry) {
					e++;
					carry = false;
				}
				if (e >= 10) {
					e -= 10;
					carry = true;
				}
				const ElemType tmp = e;
				ris = ListInsertBack(ris, &tmp);
			}

		}
		
	}

	if (carry) {
		const ElemType e = 1;
		ris = ListInsertBack(ris, &e);
	}

	return ris;
}