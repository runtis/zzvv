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

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

size_t strlen_(const char *begin);

char* find(char *begin, char *end, int ch);

char* findNonSpace(char *begin);

char* findSpace(char *begin);

char *findNonSpaceReverse(char *rbegin, const char *rend);

char *findSpaceReverse(char *rbegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char* copy(const char *beginSource, const char *endSource, char *beginDestination);

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int));

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

void test_string();

void removeNonLetters(char *s);

void removeExtraSpaces(char *s);

void removeAdjacentEqualLetters(char *s);

void test_removeAdjacentEqualLetters();

void test_removeExtraSpaces_1();

int getWord(char *beginSearch, WordDescriptor *word);

void digitToStart(WordDescriptor word);

void digitToEnd(WordDescriptor word);

void digitToEndAndReverse(WordDescriptor word);

void digits_to_end(char *string);

void digits_to_end_and_reverse(char *string);

void letters_to_end(char *string);

void test_WordDescriptor();

#endif //UNTITLED1_STRING__H
