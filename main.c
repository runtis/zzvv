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

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols)) {
            return false;
        }
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int result = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i])) {
            result++;
        }
    }
    return result;
}

void test_countNonDescendingRowsMatrices_1() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1,
                                               1, 1},2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 6,
                                               2, 2},2, 2);
    matrix m3 = createMatrixFromArray((int[]) {5, 4,
                                               2, 3},2, 2);
    matrix m4 = createMatrixFromArray((int[]) {1, 3,
                                               7, 9},2, 2);
    matrix *ms = getMemArrayOfMatrices(4, 2, 2);
    ms[0] = m1;
    ms[1] = m2;
    ms[2] = m3;
    ms[3] = m4;
    assert(countNonDescendingRowsMatrices(ms, 4) == 2);
    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices_2() {
    matrix m1 = createMatrixFromArray((int[]) {7, 1,
                                               1, 1},2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 0,
                                               2, 2},2, 2);
    matrix m3 = createMatrixFromArray((int[]) {5, 4,
                                               2, 3},2, 2);
    matrix m4 = createMatrixFromArray((int[]) {10, 3,
                                               7, 9},2, 2);
    matrix *ms = getMemArrayOfMatrices(4, 2, 2);
    ms[0] = m1;
    ms[1] = m2;
    ms[2] = m3;
    ms[3] = m4;
    assert(countNonDescendingRowsMatrices(ms, 4) == 0);
    freeMemMatrices(ms, 4);
}

void test_countNonDescendingRowsMatrices() {
    test_countNonDescendingRowsMatrices_1();
    test_countNonDescendingRowsMatrices_2();
}

int main() {
    test_countNonDescendingRowsMatrices();

    return 0;
}