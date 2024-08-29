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

float getDistance(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i]*a[i];
    }
    return sqrtf(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int*, int)) {
    float *values = malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        values[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < i; j++) {
            if (values[i] < values[j]) {
                float temp = values[i];
                values[i] = values[j];
                values[j] = temp;
                swapRows(&m, i, j);
            }
        }
    }
    free(values);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_sortByDistances() {
    matrix m = createMatrixFromArray((int[]) {7, 12,
                                              9, 2,
                                              6, 8},3, 2);
    matrix result = createMatrixFromArray((int[]) {9, 2,
                                                   6, 8,
                                                   7, 12},3, 2);
    sortByDistances(m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

int main() {
    test_sortByDistances();

    return 0;
}