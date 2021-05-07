/*
Open bracket        {
Close bracket       }
Open parenthesis    \(
Close parenthesis   \)
Semicolon           ;
Int keyword         int
Return keyword      return
Identifier          [a-zA-Z]\w*
Integer literal     [0-9]+
*/
#include <stdio.h>
#include <assert.h>
#include "libs/structures.h"

#define FALSE 0
#define TRUE 1

char *tokens;


// The first argument is always the program itself
int main(int argc, char *argv[]) {
    // Initialization
    printf("Initializing lexer\n");

    char *file_to_lex = argv[1];

    //assert(file_to_lex != NULL);
    printf("File to lex: %s\n", file_to_lex);

    tokens = (char *) malloc(53);
    tokens = "{, }, \\(, \\), ;, int, return, [a-zA-Z]\\w*, [0-9]+";
    printf("Tokens: %s", tokens);
    
    

    return 0;
}

/*
Example code for lexing text

#define MAXCHAR 1000
int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "c:\\temp\\test.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}
*/
