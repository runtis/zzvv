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
#include "libs/algorithms/for_dm/for_dm.h"
#include "libs/string_/string_.h"

double getScalarProduct(int *a, int *b, int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }
    return result;
}

long long getScalarProductRowAndCol(matrix m, int i, int j) {
    int *column = malloc(sizeof(int)*m.nRows);
    for (int g = 0; g < m.nRows; g++) {
        column[g] = m.values[g][j];
    }
    return getScalarProduct(m.values[i], column, m.nRows);
}

long long getSpecialScalarProduct(matrix m) {
    position max_pos = getMaxValuePos(m);
    position min_pos = getMinValuePos(m);
    return getScalarProductRowAndCol(m, max_pos.rowIndex, min_pos.colIndex);
}

void test_getSpecialScalarProduct() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3,3);
    assert(getSpecialScalarProduct(m) == 102);
    freeMemMatrix(&m);
}

int main() {
    test_string_1();

    return 0;
}