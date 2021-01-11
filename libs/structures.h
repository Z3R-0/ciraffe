#ifndef structures
#define structures

struct string_pair {
    char *key;
    char *value;
};

struct node {
    struct string_pair this;
    struct node next;
};

struct dictionary {
    struct node *nodes;
    int size;
};

struct dictionary create_dictionary();
void destroy_dictionary(struct dictionary *_dictionary);
void add_node(struct dictionary _dictionary, char *key, char *value);
void remove_node(struct dictionary _dictionary, struct node node_to_remove);
int compare_dictionary(struct dictionary _original, struct dictionary _match);
int compare_node(struct node _original, struct node _match);

#endif