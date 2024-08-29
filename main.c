#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"

int getMinInArea(matrix m) {
    if (m.nRows > 0 && m.nCols > 0) {
        position max_pos = getMaxValuePos(m);
        int min = m.values[max_pos.rowIndex][max_pos.colIndex];
        for (int i = 0; i < m.nRows; i++) {
            int index = max_pos.colIndex - (max_pos.rowIndex - i);
            for (int j = index; j < max_pos.rowIndex*2 - i + 1 && j < m.nCols; j++) {
                if (m.values[i][j] < min) {
                    min = m.values[i][j];
                }
            }
        }
        return min;
    } else {
        return 0;
    }
}

void test_getMinInArea_1() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    assert(getMinInArea(m) == 0);
    freeMemMatrix(&m);
}

void test_getMinInArea_2() {
    matrix m = createMatrixFromArray((int[]) {10, 7, 5, 6,
                                              3, 11, 8, 9,
                                              4, 1, 12, 2},3, 4);
    assert(getMinInArea(m) == 5);
    freeMemMatrix(&m);
}

void test_getMinInArea_3() {
    matrix m = createMatrixFromArray((int[]) {6, 8, 9, 2,
                                              7, 12, 3, 4,
                                              10, 11, 5, 1},3, 4);
    assert(getMinInArea(m) == 6);
    freeMemMatrix(&m);
}

void test_getMinInArea() {
    test_getMinInArea_1();
    test_getMinInArea_2();
    test_getMinInArea_3();
}

int main() {
    test_getMinInArea();

    return 0;
}