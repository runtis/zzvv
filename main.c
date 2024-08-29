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

int countNUnique(int *a, int n) {
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
        }
    }
    free(unique_numbers);
    return len;
}

int countEqClassesByRowsSum(matrix m) {
    int *unique_sums = malloc(sizeof(int)*m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        unique_sums[i] = getSum(m.values[i], m.nCols);
    }
    int result = countNUnique(unique_sums, m.nRows);
    free(unique_sums);
    return result;
}

void test_countEqClassesByRowsSum_1() {
    matrix m = createMatrixFromArray((int[]) {},0, 0);
    assert(countEqClassesByRowsSum(m) == 0);
    freeMemMatrix(&m);
}

void test_countEqClassesByRowsSum_2() {
    matrix m = createMatrixFromArray((int[]) {7, 1,
                                              2, 7,
                                              5, 4,
                                              4, 3,
                                              1, 6,
                                              8, 0},6, 2);
    assert(countEqClassesByRowsSum(m) == 3);
    freeMemMatrix(&m);
}

void test_countEqClassesByRowsSum() {
    test_countEqClassesByRowsSum_1();
    test_countEqClassesByRowsSum_2();
}

int main() {
    test_countEqClassesByRowsSum();

    return 0;
}