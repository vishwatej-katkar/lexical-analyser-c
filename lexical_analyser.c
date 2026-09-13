#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "lexical_analyser.h"



/*
 * Function Name : check_Identifier_or_Keyword
 * 
 * Description   : Reads a sequence of characters from a file and determines whether it is a
 *                 valid identifier or a reserved keyword, then prints the classification.
 * 
 * Parameters    : fp  - Pointer to input file being analyzed
 *                 ch  - First character of the token
 * 
 * Return        : void
 * 
 */
void check_Identifier_or_Keyword(FILE *fp, uchar ch){

    uchar buff[50],i=0,found=0;

    char *ptr = (char *)buff;      // Pointer for string comparison

    /* Read continuous characters forming identifier or keyword */
    while((isalpha(ch)) || (isdigit(ch)) || ch == '_'){

        buff[i++] = ch;            // Store character in buffer

        ch = fgetc(fp);            // Read next character

    }

    buff[i] = '\0';

    /* Compare buffer with all known keywords */
    for(int j=0; j<keyword_count; j++){

        if(!strcmp(ptr, keyword[j])){

            printf("| %-25s | %-25s |\n", buff, "Keyword");
           
            found = 1;

            break;

        }
        
    }

     /* If not found in keyword list, classify as identifier */
    if(!found){

        printf("| %-25s | %-25s |\n", buff, "Identifier");

    }

    ungetc(ch, fp);              // Push back the last read character

    return;
    
}



/*
 * Function Name : check_constant
 * 
 * Description   : Reads a numeric sequence (integer or floating point) from the input file
 *                 and classifies it as a constant for lexical analysis.
 * 
 * Parameters    : fp  - Pointer to input file being analyzed
 *                 ch  - First character of the token
 * 
 * Return        : void
 * 
 */
void check_constant(FILE *fp, uchar ch){

    uchar buff[50],i=0,found=0;

    /* Read digits and optional decimal point to form numeric constant */
    while( isdigit(ch) || ch == '.'){

        buff[i++] = ch;           // Store character in buffer

        ch = fgetc(fp);           // Read next character

    }

    buff[i] = '\0';

    printf("| %-25s | %-25s |\n", buff, "Constant");     // Print constant classification

    ungetc(ch, fp);               // Push back the last non-digit character

    return;

}



/*
 * Function Name : check_SpeChar_PrePro_Str_or_Operator
 * 
 * Description   : Identifies and classifies the input token as a preprocessor directive,
 *                 string literal, operator, or special character while scanning source code.
 * 
 * Parameters    : fp  - Pointer to input file being analyzed
 *                 ch  - Current character from input stream
 * 
 * Return        : void
 * 
 */
void check_SpeChar_PrePro_Str_or_Operator(FILE *fp, uchar ch){

    uchar buff[50],i=0,found=0;
    char next;
    char op[4];

    char *ptr = buff;

    /* Check for preprocessor directive (starts with '#') */
    if(ch == '#'){

        buff[i++] = ch;
        
        while((ch = fgetc(fp)) != EOF && ch != '\n' && ch != '\r'){

            buff[i++] = ch;
    
        }

        buff[i] = '\0';

        printf("| %-25s | %-25s |\n", buff, "Preprocessor Directive");

        return;
    }

    /* Check for string literal (enclosed in double quotes) */
    if(ch == '"'){

        buff[i++] = ch;

        while((ch = fgetc(fp)) != EOF){

            buff[i++] = ch;
            if(ch == '"' && buff[i-2] != '\\')    // Handle escaped quotes
                break;

        }

        buff[i] = '\0';

        printf("| %-25s | %-25s |\n", buff, "String Literal");

        return;
    }

    /* Collect punctuation characters (possible operators/special chars) */
    // Check 2-character operator first
    next = fgetc(fp);
    if(next != EOF) {
        op[0] = ch;
        op[1] = next;
        op[2] = '\0';
        for(int i=0; i<operator_count; i++) {
            if(strcmp(op, operators[i]) == 0) {
                printf("| %-25s | %-25s |\n", op, "Operator");
                return;
            }
        }
        ungetc(next, fp); // not 2-char operator, put back next
    }

    // Check single-character operator
    op[0] = ch;
    op[1] = '\0';
    for(int i=0; i<operator_count; i++) {
        if(strcmp(op, operators[i]) == 0) {
            printf("| %-25s | %-25s |\n", op, "Operator");
            return;
        }
    }

    // Otherwise, special character
    printf("| %-25s | %-25s |\n", op, "Special Character");

}


/*
 * Function Name : print_table_header
 * 
 * Description   : Prints a formatted table header for displaying tokens and their types
 *                 during lexical analysis output.
 */
void print_table_header(void){

    printf("---------------------------------------------------------\n");
    printf("| %-25s | %-25s |\n", "TOKEN", "TYPE");
    printf("---------------------------------------------------------\n");

}


