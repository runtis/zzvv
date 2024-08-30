//
// Created by yaros on 13.04.2024.
//

#ifndef UNTITLED1_STRING__H
#define UNTITLED1_STRING__H

#include "string_.h"
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

void test_string_1();

#endif //UNTITLED1_STRING__H
