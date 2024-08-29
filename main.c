#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"


int getMax(int *a, int n) {
    int result = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > result) {
            result = a[i];
        }
    }
    return result;
}

void sortRowsByMinElement(matrix *m) {
    int rows = m->nRows;
    for (int i = 0; i < rows - 1; i++) {
        int max = getMax(m->values[i], rows);
        int row_index = i;
        for (int j = i + 1; j < rows; j++) {
            int max_of_row = getMax(m->values[j], rows);
            if (max_of_row < max) {
                max = max_of_row;
                row_index = j;
            }
        }

        if (row_index != i) {
            swapRows(m, i, row_index);
        }
    }
}

void test_sortRowsByMinElement_1() {
    matrix m = createMatrixFromArray((int[]) {7, 1, 2,
                                              1, 8, 1,
                                              3, 2, 3},3, 3);
    matrix result = createMatrixFromArray((int[]) {3, 2, 3,
                                                   7, 1, 2,
                                                   1, 8, 1},3, 3);
    sortRowsByMinElement(&m);

    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortRowsByMinElement_2() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    sortRowsByMinElement(&m);
    freeMemMatrix(&m);
}

void test_sortRowsByMinElement() {
    test_sortRowsByMinElement_1();
    test_sortRowsByMinElement_2();
}


int main() {
    //test_matrix();
    test_sortRowsByMinElement();

    return 0;
}