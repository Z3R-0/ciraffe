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

char *recognized_tokens;

char * match_tokens(char *, FILE *);

// The first argument is always the program itself
int main(int argc, char *argv[]) {
    // Initialization
    printf("Initializing lexer\n");

    char *file_to_lex = argv[1];

    printf("File to lex: %s\n", file_to_lex);
    
    FILE *fp;
    fp = fopen(file_to_lex, "r");
    assert(fp != NULL);

    recognized_tokens = (char *) malloc(45);
    recognized_tokens = "{,},\\(,\\),;,int,return,[a-zA-Z]\\w*,[0-9]+";
    printf("Tokens: %s", recognized_tokens);
    
    printf("Lexing tokens");
    char *lexed_tokens = match_tokens(recognized_tokens, fp);
    
    assert(lexed_tokens != NULL);
    
    return 0;
}

char * match_tokens(char *_tokens, FILE *fp) {
	return NULL;
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
