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

int get_matrix_norm(matrix m) {
    int res = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int norm = abs(m.values[i][j]);
            if (norm > res) {
                res = norm;
            }
        }
    }
    return res;
}

void print_matrices_with_min_norm(matrix *ms, int n) {
    if (n > 0) {
        int *norms = malloc(sizeof(int)*n);
        norms[0] = get_matrix_norm(ms[0]);
        int min_norm = norms[0];
        for (int i = 1; i < n; i++) {
            norms[i] = get_matrix_norm(ms[i]);
            if (norms[i] < min_norm) {
                min_norm = norms[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (norms[i] == min_norm) {
                outputMatrix(ms[i]);
            }
        }
    }
}

void test_print_matrices_with_min_norm_1() {
    matrix *ms = getMemArrayOfMatrices(0, 0, 0);
    print_matrices_with_min_norm(ms, 0);
}

void test_print_matrices_with_min_norm_2() {
    matrix m1 = createMatrixFromArray((int[]) {2, 1,
                                               1, 3},2, 2);
    matrix m2 = createMatrixFromArray((int[]) {1, 1,
                                               2, 1},2, 2);
    matrix m3 = createMatrixFromArray((int[]) {3, 4,
                                               1, 5},2, 2);
    matrix m4 = createMatrixFromArray((int[]) {4, 4,
                                               4, 1},2, 2);
    matrix m5 = createMatrixFromArray((int[]) {2, 1,
                                               1, 2},2, 2);
    matrix *ms = getMemArrayOfMatrices(5, 3, 2);
    ms[0] = m1;
    ms[1] = m2;
    ms[2] = m3;
    ms[3] = m4;
    ms[4] = m5;
    print_matrices_with_min_norm(ms, 5);
    freeMemMatrices(ms, 5);
}

void test_print_matrices_with_min_norm() {
    test_print_matrices_with_min_norm_1();
    test_print_matrices_with_min_norm_2();
}

int main() {
    test_print_matrices_with_min_norm();

    return 0;
}