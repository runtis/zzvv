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

int getNSpecialElement2(matrix m) {
    int result = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            bool is_lefts_less = true;
            for (int g = j - 1; g >= 0; g--) {
                if (m.values[i][g] >= m.values[i][j]) {
                    is_lefts_less = false;
                }
            }
            if (is_lefts_less) {
                bool is_rights_more = true;
                for (int g = j + 1; g < m.nCols; g++) {
                    if (m.values[i][g] <= m.values[i][j]) {
                        is_rights_more = false;
                    }
                }
                if (is_rights_more) {
                    result++;
                }
            }
        }
    }
    return result;
}

void test_getNSpecialElement2() {
    matrix m = createMatrixFromArray((int[]) {2, 3, 5, 5, 4,
                                              6, 2, 3, 8, 12,
                                              12, 12, 2, 1, 2},3, 5);
    assert(getNSpecialElement2(m) == 4);
    freeMemMatrix(&m);
}

int main() {
    test_getNSpecialElement2();

    return 0;
}