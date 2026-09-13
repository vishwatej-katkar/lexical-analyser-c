#include<stdio.h>
#include <ctype.h>
#include "lexical_analyser.h"

/* NOTE : Command for compilation : gcc lexical_analyser.c tokens.c main.c -o <Output File Name> 
                                    Don't need to compile input_file.c beacuse its our input to
                                    the program.
          Command for running the executable file : ./<Output File Name> 
*/


int main(){

    FILE *fp = fopen("input_file.c", "r");      // Open input C source file

    int ch;
    
    /* Print table header for tokens */
    print_table_header();

    /* Read file character by character until EOF */
    while((ch = fgetc(fp)) != EOF){


        if(isspace(ch)){                     // Skip whitespace characters
            continue;
        }

        if(isalpha(ch)){                     // Alphabetic: identifier or keyword
            
            check_Identifier_or_Keyword(fp, (uchar)ch);

            continue;

        }

        if(isdigit(ch)){                     // Numeric: constant

            check_constant(fp, (uchar)ch);

            continue;
        }

        if(ispunct(ch)){                     // Punctuation: operator, string, preprocessor, special character

            check_SpeChar_PrePro_Str_or_Operator(fp, (uchar)ch);

            continue;
        }


    }
    
    printf("---------------------------------------------------------\n");
    printf("              Tokens Generated Successfully\n");
    printf("---------------------------------------------------------\n");


    fclose(fp);           // Close the input file

    return 0;

}