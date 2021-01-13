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

#include "structures.h"

#define FALSE 0
#define TRUE 1

struct dictionary recognized_tokens;

// The first argument is always the program itself
int main(int argc, char *argv[]) {
    // Initialization
    char *file_to_parse = argv[1];
    recognized_tokens = recognized_token_builder();


    // 
    token_cleaner(recognized_tokens);
}

struct dictionary recognized_token_builder() {
    struct dictionary dict = create_dictionary();

    add_node(dict, "open bracket", "{");
    add_node(dict, "close bracket", "}");
    add_node(dict, "open parenthesis", "\(");
    add_node(dict, "open parenthesis", "\)");
    add_node(dict, "semicolon", ";");
    add_node(dict, "int keyword", "int");
    add_node(dict, "return keyword", "return");
    add_node(dict, "identifier", "[a-zA-Z]\w*"); // regex for catching words seperated by whitespace
    add_node(dict, "integer literal", "[0-9]+"); // regex for catching numbers
}

void token_cleaner(struct dictionary dict) {
    destroy_dictionary(&dict);
}

char get_char(){
    char token = ' ';


    return token;
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
