#ifndef structures
#define structures

struct string_pair {
    char *key , *value;
};

struct node {
    struct string_pair this;
    struct node *next;
};

struct dictionary {
    struct node *nodes;
    int size;
};

struct dictionary * create_dictionary();
void print_dictionary(struct dictionary *_dictionary);
void free_dictionary(struct dictionary *_dictionary);
struct dictionary * add_node(struct dictionary *_dictionary, char *key, char *value);
struct dictionary * remove_node(struct dictionary *_dictionary, struct node node_to_remove);
int compare_dictionary(struct dictionary *_original, struct dictionary *_match);
int compare_node(struct node _original, struct node _match);
struct node * look_up_key(struct dictionary *_dictionary, char * _key);
struct node * look_up_value(struct dictionary *_dictionary, char * _value);

#endif