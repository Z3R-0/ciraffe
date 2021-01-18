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

struct dictionary *recognized_tokens;

void token_cleaner(struct dictionary *_dictionary);
void recognized_token_builder();

// The first argument is always the program itself
int main(int argc, char *argv[]) {
    // Initialization
    printf("Initializing lexer\n");

    char *file_to_lex = argv[1];

    assert(file_to_lex != NULL);
    printf("File to lex: %s\n", file_to_lex);

    // Token dictionary builder
    recognized_token_builder();
    assert(recognized_tokens->size > 0);

    print_dictionary(*recognized_tokens);

    // Clean up
    token_cleaner(recognized_tokens);

    printf("Finished up!\n");

    return 0;
}

void recognized_token_builder() {
    recognized_tokens = create_dictionary();
    
    *recognized_tokens = add_node(*recognized_tokens, "open bracket", "{");
    *recognized_tokens = add_node(*recognized_tokens, "close bracket", "}");
    *recognized_tokens = add_node(*recognized_tokens, "open parenthesis", "\\(");
    *recognized_tokens = add_node(*recognized_tokens, "close parenthesis", "\\)");
    *recognized_tokens = add_node(*recognized_tokens, "semicolon", ";");
    *recognized_tokens = add_node(*recognized_tokens, "int keyword", "int");
    *recognized_tokens = add_node(*recognized_tokens, "return keyword", "return");
    *recognized_tokens = add_node(*recognized_tokens, "identifier", "[a-zA-Z]\\w*"); // regex for catching words seperated by whitespace
    *recognized_tokens = add_node(*recognized_tokens, "integer literal", "[0-9]+"); // regex for catching numbers
}

void token_cleaner(struct dictionary *_dictionary) {
    free_dictionary(_dictionary);
}

/*
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
