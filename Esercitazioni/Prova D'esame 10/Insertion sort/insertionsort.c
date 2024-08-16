#include <stdlib.h>


void InsertionSort(int* v, size_t v_size) {

    for (size_t i = 1; i < v_size; i++) {

        int elem = v[i];
        int j = i - 1;

        size_t index = i;

        while (j >= 0 && v[j] > v[index]) {

            v[j + 1] = v[j];
            j--;
            index--;
            v[j + 1] = elem;
        }

    }

    return;

 }
