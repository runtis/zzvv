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


bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (isSquareMatrix(&m1) && isSquareMatrix(&m2) && m1.nRows == m2.nRows) {
        matrix mul = mulMatrices(m1, m2);

        if (isEMatrix(&mul)) {
            freeMemMatrix(&mul);
            return true;
        } else {
            freeMemMatrix(&mul);
            return false;
        }
    }
}

void test_isMutuallyInverseMatrices_1() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    transposeIfMatrixHasNotEqualSumOfRows(&m);
    freeMemMatrix(&m);
}

void test_isMutuallyInverseMatrices_2() {
    matrix m1 = createMatrixFromArray((int[]) {3, -5,
                                               1, -2},2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3},2, 2);
    assert(isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices_3() {
    matrix m1 = createMatrixFromArray((int[]) {4, -5,
                                               1, -2},2, 2);
    matrix m2 = createMatrixFromArray((int[]) {2, -5,
                                               1, -3},2, 2);
    assert(!isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_isMutuallyInverseMatrices() {
    test_isMutuallyInverseMatrices_1();
    test_isMutuallyInverseMatrices_2();
    test_isMutuallyInverseMatrices_3();
}

int main() {
    test_isMutuallyInverseMatrices();

    return 0;
}