#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int countValues(const int *a, int n, int value) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value) {
            result++;
        }
    }
    return result;
}

int countZeroRows(matrix m) {
    int result = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols) {
            result++;
        }
    }
    return result;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *zero_rows = malloc(sizeof(int)*nMatrix);
    int max_zeros = 0;
    for (int i = 0; i < nMatrix; i++) {
        zero_rows[i] = countZeroRows(ms[i]);
        if (zero_rows[i] > max_zeros) {
            max_zeros = zero_rows[i];
        }
    }

    for (int i = 0; i < nMatrix; i++) {
        if (zero_rows[i] == max_zeros) {
            outputMatrix(ms[i]);
        }
    }
    free(zero_rows);
}

void test_printMatrixWithMaxZeroRows() {
    matrix m1 = createMatrixFromArray((int[]) {0, 1,
                                               1, 0,
                                               0, 0},3, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 1,
                                               2, 1,
                                               1, 1},3, 2);
    matrix m3 = createMatrixFromArray((int[]) {0, 0,
                                               0, 0,
                                               4, 7},3, 2);
    matrix m4 = createMatrixFromArray((int[]) {0, 0,
                                               0, 1,
                                               0, 0},3, 2);
    matrix m5 = createMatrixFromArray((int[]) {0, 1,
                                               0, 2,
                                               0, 3},3, 2);
    matrix *ms = getMemArrayOfMatrices(5, 3, 2);
    ms[0] = m1;
    ms[1] = m2;
    ms[2] = m3;
    ms[3] = m4;
    ms[4] = m5;
    assert(countZeroRows(m1) == 1);
    assert(countZeroRows(m2) == 0);
    assert(countZeroRows(m3) == 2);
    assert(countZeroRows(m4) == 2);
    assert(countZeroRows(m5) == 0);
    printMatrixWithMaxZeroRows(ms, 5);
    freeMemMatrices(ms, 5);
}

int main() {
    test_printMatrixWithMaxZeroRows();

    return 0;
}