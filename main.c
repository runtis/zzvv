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

double getScalarProduct(int *a, int *b, int n) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }
    return result;
}

double getCosine(int *a, int *b, int n) {
    float len_a = getDistance(a, n);
    float len_b = getDistance(b, n);
    if (len_a == 0 || len_b == 0) {
        fprintf(stderr, "zeros vector`s length");
    }
    return getScalarProduct(a, b, n) / (len_a * len_b);
}

int getVectorIndexWithMaxAngle(matrix m, int *b) {
    int result = 0;
    double max_cos = getCosine(m.values[0], b, m.nCols);
    for (int i = 1; i < m.nRows; i++) {
        double cos = getCosine(m.values[i], b, m.nCols);
        if (cos > max_cos) {
            max_cos = cos;
            result = i;
        }
    }
    return result;
}

void test_getVectorIndexWithMaxAngle() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3,3);
    int b[] = {5, 8, 9};
    assert(getVectorIndexWithMaxAngle(m, b) == 1);
    freeMemMatrix(&m);
}

int main() {
    test_getVectorIndexWithMaxAngle();

    return 0;
}