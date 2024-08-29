#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m)) {
        *m = mulMatrices(*m, *m);
    }
}

void test_getSquareOfMatrixIfSymmetric_1() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2,
                                              4, 3, 6,
                                              2, 6, 5},3, 3);
    matrix result = createMatrixFromArray((int[]) {21, 28, 36,
                                                   28, 61, 56,
                                                   36, 56, 65},3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_getSquareOfMatrixIfSymmetric_2() {
    matrix m = createMatrixFromArray((int[]) {1, 4, 2,
                                              3, 3, 6,
                                              2, 6, 5},3, 3);
    matrix result = createMatrixFromArray((int[]) {1, 4, 2,
                                                   3, 3, 6,
                                                   2, 6, 5},3, 3);
    getSquareOfMatrixIfSymmetric(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_getSquareOfMatrixIfSymmetric_3() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    getSquareOfMatrixIfSymmetric(&m);
    freeMemMatrix(&m);
}

void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_1();
    test_getSquareOfMatrixIfSymmetric_2();
    test_getSquareOfMatrixIfSymmetric_3();
}

int main() {
    //test_matrix();
    test_getSquareOfMatrixIfSymmetric();

    return 0;
}