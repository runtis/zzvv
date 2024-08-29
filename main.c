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

int getNSpecialElement(matrix m) {
    int result = 0;
    for (int i = 0; i < m.nCols; i++) {
        int sum = 0;
        for (int j = 0; j < m.nRows; j++) {
            sum += m.values[j][i];
        }

        for (int j = 0; j < m.nRows; j++) {
            if (m.values[j][i] > sum - m.values[j][i]) {
                result++;
            }
        }
    }
    return result;
}

void test_getNSpecialElement_1() {
    matrix m = createMatrixFromArray((int[]) {}, 0, 0);
    assert(getNSpecialElement(m) == 0);
    freeMemMatrix(&m);
}

void test_getNSpecialElement_2() {
    matrix m = createMatrixFromArray((int[]) {3, 5, 5, 4,
                                              2, 3, 6, 7,
                                              12, 2, 1, 2}, 3, 4);
    assert(getNSpecialElement(m) == 2);
    freeMemMatrix(&m);
}

void test_getNSpecialElement() {
    test_getNSpecialElement_1();
    test_getNSpecialElement_2();
}

int main() {
    test_getNSpecialElement();

    return 0;
}