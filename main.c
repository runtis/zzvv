#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"

bool isUnique(int *a, int n) {
    int *unique_numbers = malloc(sizeof(int)*n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        bool is_in = false;
        for (int j = 0; j < len && !is_in; j++) {
            if (a[i] == unique_numbers[j]) {
                is_in = true;
            }
        }

        if (!is_in) {
            unique_numbers[len++] = a[i];
        } else {
            free(unique_numbers);
            return false;
        }
    }
    return true;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix *m) {
    if (isSquareMatrix(m)) {
        int *sums = malloc(sizeof(int)*m->nRows);
        for (int i = 0; i < m->nRows; i++) {
            sums[i] = getSum(m->values[i], m->nCols);
        }

        if (isUnique(sums, m->nRows)) {
            transposeSquareMatrix(m);
            free(sums);
        }
    }
}

void test_transposeIfMatrixHasNotEqualSumOfRows_1() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    freeMemMatrix(&m);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_2() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2,
                                              3, 3, 6,
                                              2, 6, 5},3, 3);
    matrix result = createMatrixFromArray((int[]) {1, 3, 2,
                                                   4, 3, 6,
                                                   2, 6, 5},3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_3() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2, 4,
                                              3, 3, 6, 5,
                                              2, 6, 5, 7},3, 4);
    matrix result = createMatrixFromArray((int[]) {1, 4, 2, 4,
                                                   3, 3, 6, 5,
                                                   2, 6, 5, 7},3, 4);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows_4() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2,
                                              4, 1, 2,
                                              1, 1, 5},3, 3);
    matrix result = createMatrixFromArray((int[]) {1, 4, 2,
                                                   4, 1, 2,
                                                   1, 1, 5},3, 3);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_1();
    test_transposeIfMatrixHasNotEqualSumOfRows_2();
    test_transposeIfMatrixHasNotEqualSumOfRows_3();
    test_transposeIfMatrixHasNotEqualSumOfRows_4();
}

int main() {
    test_transposeIfMatrixHasNotEqualSumOfRows();

    return 0;
}