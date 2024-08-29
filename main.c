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

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long res = 0;
    for (int i = 0; i < m.nCols + m.nRows - 1; i++) {
        int row = max(0, m.nRows - i - 1);
        int col = max(0, i - m.nRows + 1);
        if (row != col) {
            int max_value = INT_MIN;
            while (row < m.nRows && col < m.nCols) {
                max_value = max(max_value, m.values[row][col]);
                row++;
                col++;
            }
            res += max_value;
        }
    }
    return res;
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray((int[]) {3, 2, 5, 4,
                                              1, 3, 6, 3,
                                              3, 2, 1, 2},3, 4);
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(&m);
}


int main() {
    test_findSumOfMaxesOfPseudoDiagonal();

    return 0;
}