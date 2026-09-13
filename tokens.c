#include<stdio.h>
#include "lexical_analyser.h"

/* -------------------- Keywords -------------------- */
const char *keyword[] = { 
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline",
    "int", "long", "register", "restrict", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", "_Bool"
};

int keyword_count = sizeof(keyword) / sizeof(keyword[0]);

/* -------------------- Operators -------------------- */ 
const char *operators[] = {
    "+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=",
    "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~",
    "<<", ">>", "<<=", ">>=", "?", ":"
};
int operator_count = sizeof(operators) / sizeof(operators[0]);

/* -------------------- Special Characters-------------------- */
const char *specialCharacter[] = {
    "(", ")", "{", "}", "[", "]", ";", ":", ",", ".", "->", "#"
};
int specialChar_Count = sizeof(specialCharacter) / sizeof(specialCharacter[0]);