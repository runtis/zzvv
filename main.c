#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/ordered_set/ordered_set.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"


void test_ordered() {
    int arr[5];
    inputArray_(arr, 3);
    outputArray_(arr, 3);
    ordered_array_set or_arr_1 = ordered_array_set_create_from_array(arr, 3);
    ordered_array_set_print(or_arr_1);
    ordered_array_set_insert(&or_arr_1, 1);
    ordered_array_set_print(or_arr_1);

    inputArray_(arr, 3);
    ordered_array_set or_arr_2 = ordered_array_set_create_from_array(arr, 3);
    ordered_array_set_print(or_arr_2);
    ordered_array_set_insert(&or_arr_2, 1);
    ordered_array_set_print(or_arr_2);

    ordered_array_set result = ordered_array_set_intersection(or_arr_1, or_arr_2);
    ordered_array_set_print(result);

    result = ordered_array_set_union(or_arr_1, or_arr_2);
    ordered_array_set_print(result);

    printf("%d\n", ordered_array_set_isEqual(or_arr_1, or_arr_2));
    ordered_array_set_deleteElement(&or_arr_1, 1);
    ordered_array_set_print(or_arr_1);
    printf("%d\n", ordered_array_set_isSubset(or_arr_1, or_arr_2));

    result = ordered_array_set_difference(or_arr_2, or_arr_1);
    printf("diff\n");
    ordered_array_set_print(result);
    result = ordered_array_set_symmetricDifference(or_arr_1, or_arr_2);
    printf("sy_diff\n");
    ordered_array_set_print(result);
}

int main() {
    //test_ordered();
    //test1();
    test_matrix();


    return 0;
}