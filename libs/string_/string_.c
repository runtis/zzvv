#include "string_.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char* findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char* findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin >= rend && !isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0' && *rhs != '\0') {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

void test_find_1() {
    char string[] = "hello";

    assert(find(string, string + 5, 'e') == string + 1);
}

void test_find_2() {
    char string[] = "hello";

    assert(find(string, string + 5, 'h') == string);
}

void test_find_3() {
    char string[] = "hello";

    assert(find(string, string + 5, 'o') == string + 4);
}

void test_find_4() {
    char string[] = "hello";

    assert(find(string, string + 5, 'g') == string + 5);
}

void test_find_non_space_1() {
    char string[] = "hello";

    assert(findNonSpace(string) == string);
}

void test_find_non_space_2() {
    char string[] = "  llo";

    assert(findNonSpace(string) == string + 2);
}

void test_find_non_space_3() {
    char string[] = "    o";

    assert(findNonSpace(string) == string + 4);
}

void test_find_non_space_4() {
    char string[] = "     ";

    assert(findNonSpace(string) == string + 5);
}

void test_find_space_1() {
    char string[] = " ello";

    assert(findSpace(string) == string);
}

void test_find_space_2() {
    char string[] = "he lo";

    assert(findSpace(string) == string + 2);
}

void test_find_space_3() {
    char string[] = "hello";

    assert(findSpace(string) == string + 5);
}

void test_find_space_4() {
    char string[] = "hell ";

    assert(findSpace(string) == string + 4);
}

void test_find_non_space_reverse_1() {
    char string[] = "hello";

    assert(findNonSpaceReverse(string + 4, string) == string + 4);
}

void test_find_non_space_reverse_2() {
    char string[] = "hel  ";

    assert(findNonSpaceReverse(string + 4, string) == string + 2);
}

void test_find_non_space_reverse_3() {
    char string[] = "h    ";

    assert(findNonSpaceReverse(string + 4, string) == string);
}

void test_find_non_space_reverse_4() {
    char string[] = "     ";

    assert(findNonSpaceReverse(string + 4, string) == string - 1);
}

void test_find_space_reverse_1() {
    char string[] = "hello";

    assert(findSpaceReverse(string + 4, string) == string - 1);
}

void test_find_space_reverse_2() {
    char string[] = "hel  ";

    assert(findSpaceReverse(string + 4, string) == string + 4);
}

void test_find_space_reverse_3() {
    char string[] = "h   o";

    assert(findSpaceReverse(string + 4, string) == string + 3);
}

void test_find_space_reverse_4() {
    char string[] = " ello";

    assert(findSpaceReverse(string + 4, string) == string);
}

void test_is_strings_equal_1() {
    char string1[] = "Hello";
    char string2[] = "Hello";

    assert(strcmp_(string1, string2) == 0);
}

void test_is_strings_equal_2() {
    char string1[] = "Hello";
    char string2[] = "Hallo";

    assert(strcmp_(string1, string2) > 0);
}

void test_is_strings_equal_3() {
    char string1[] = "Hello";
    char string2[] = "Hellower";

    assert(strcmp_(string1, string2) < 0);
}

void test_strcmp_(){
    test_is_strings_equal_1();
    test_is_strings_equal_2();
    test_is_strings_equal_3();
}

void test_string_1(){
    test_find_1();
    test_find_2();
    test_find_3();
    test_find_4();
    test_find_non_space_1();
    test_find_non_space_2();
    test_find_non_space_3();
    test_find_non_space_4();
    test_find_space_1();
    test_find_space_2();
    test_find_space_3();
    test_find_space_4();
    test_find_non_space_reverse_1();
    test_find_non_space_reverse_2();
    test_find_non_space_reverse_3();
    test_find_non_space_reverse_4();
    test_find_space_reverse_1();
    test_find_space_reverse_2();
    test_find_space_reverse_3();
    test_find_space_reverse_4();
}

void test_copy() {
    char string[] = "hahh";
    char new_string[4];
    copy(string, string + 3, new_string);
    char result[] = "hah";

    assert(strcmp_(new_string, result) == 0);
}

void test_copyIf() {
    char string[] = "hahh";
    char new_string[4];
    copyIf(string, string + 3, new_string, (int (*)(int)) is_h);
    char result[] = "hh";

    assert(strcmp_(new_string, result) == 0);
}

void test_copyIfReverse() {
    char string[] = "haw";
    char new_string[3];
    copyIfReverse(string + 3, string, new_string, (int (*)(int)) is_h);
    char result[] = "wh";

    assert(strcmp_(new_string, result) == 0);
}

void test_copy_full(){
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

void test_string(){
    test_string_1();
    test_strcmp_();
    test_copy_full();
}