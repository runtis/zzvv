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

void swapPenultimateRow(matrix m) {
    if (isSquareMatrix(&m)) {
        int *column = malloc(sizeof(int)*m.nRows);
        position min_pos = getMinValuePos(m);
        for (int i = 0; i < m.nRows; i++) {
            column[i] = m.values[i][min_pos.colIndex];
        }
        for (int j = 0; j < m.nCols; j++) {
            m.values[m.nCols - 2][j] = column[j];
        }
        free(column);
    }
}

void test_swapPenultimateRow_1() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    swapPenultimateRow(m);
    freeMemMatrix(&m);
}

void test_swapPenultimateRow_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 1},3, 3);
    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   1, 4, 7,
                                                   7, 8, 1},3, 3);
    swapPenultimateRow(m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_swapPenultimateRow() {
    test_swapPenultimateRow_1();
    test_swapPenultimateRow_2();
}

int main() {
    test_swapPenultimateRow();

    return 0;
}