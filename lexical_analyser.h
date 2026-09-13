#ifndef LEXICAL_ANALYSER_H
#define LEXICAL_ANALYSER_H


#include<stdio.h>

typedef unsigned char uchar;
typedef unsigned int uint;

extern const char *keyword[];
extern int keyword_count;

extern const char *operators[];
extern int operator_count;

extern const char *specialCharacter[];
extern int specialChar_Count;


void check_Identifier_or_Keyword(FILE *fp, uchar ch);

void check_constant(FILE *fp, uchar ch);

void check_SpeChar_PrePro_Str_or_Operator(FILE *fp, uchar ch);

void print_table_header(void);

#endif