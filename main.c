#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"


void swap_rows_with_min_and_max_elements(matrix *m) {
    position max_pos = getMaxValuePos(*m);
    position min_pos = getMinValuePos(*m);
    if (max_pos.rowIndex != min_pos.rowIndex) {
        swapRows(m, max_pos.rowIndex, min_pos.rowIndex);
    }
}

void test_swap_rows_with_min_and_max_elements_1() {
    matrix m = createMatrixFromArray((int[]) {9, 4, 3,
                                              5, 2, 6,
                                              7, 8, 1}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {7, 8, 1,
                                                   5, 2, 6,
                                                   9, 4, 3}, 3, 3);
    swap_rows_with_min_and_max_elements(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_swap_rows_with_min_and_max_elements_2() {
    matrix m = createMatrixFromArray((int[]) {7, 4, 3,
                                              5, 2, 6,
                                              9, 8, 1}, 3, 3);
    matrix result = createMatrixFromArray((int[]) {7, 4, 3,
                                                   5, 2, 6,
                                                   9, 8, 1}, 3, 3);
    swap_rows_with_min_and_max_elements(&m);
    assert(areTwoMatricesEqual(&m, &result));
    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_swap_rows_with_min_and_max_elements() {
    test_swap_rows_with_min_and_max_elements_1();
    test_swap_rows_with_min_and_max_elements_2();
}

int main() {
    //test_matrix();
    test_swap_rows_with_min_and_max_elements();

    return 0;
}