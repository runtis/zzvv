#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"


int getMin(int *a, int n) {
    int result = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < result) {
            result = a[i];
        }
    }
    return result;
}

void sortColsByMinElement(matrix *m) {
    int cols = m->nCols;
    int rows = m->nRows;

    for (int i = 0; i < cols - 1; i++) {
        int *column = malloc(sizeof(int) * rows);

        for (int j = 0; j < rows; j++) {
            column[j] = m->values[j][i];
        }

        int min = getMin(column, rows);
        int index = i;

        for (int j = i + 1; j < cols; j++) {
            int *column2 = malloc(sizeof(int) * rows);
            for (int g = 0; g < rows; g++) {
                column2[g] = m->values[g][j];
            }
            int new_min = getMin(column2, rows);
            if (new_min < min) {
                min = new_min;
                index = j;
            }
        }
        if (index != i) {
            swapColumns(*m, index, i);
        }
    }
}

void test_sortColsByMinElement_1() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 2, 4, 3, 3,
                                              2, 5, 1, 8, 2, 7,
                                              6, 1, 4, 4, 8, 3},3, 6);
    matrix result = createMatrixFromArray((int[]) {5, 2, 3, 3, 3, 4,
                                                   5, 1, 2, 2, 7, 8,
                                                   1, 4, 6, 8, 3, 4},3, 6);
    sortColsByMinElement(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortColsByMinElement_2() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    sortColsByMinElement(&m);
    freeMemMatrix(&m);
}

void test_sortColsByMinElement() {
    test_sortColsByMinElement_1();
    test_sortColsByMinElement_2();
}

int main() {
    //test_matrix();
    test_sortColsByMinElement();

    return 0;
}