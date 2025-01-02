#ifndef structures
#define structures

struct string_pair {
    char *key , *value;
};

struct dictionary {
    struct string_pair *string_pair;
    int size;
};

struct dictionary * create_dictionary();
void print_dictionary(struct dictionary *_dictionary);
void free_dictionary(struct dictionary *_dictionary);
struct dictionary * add(struct dictionary *_dictionary, char *key, char *value);
struct dictionary * remove_stringpair(struct dictionary *_dictionary, char *key);
int compare_dictionary(struct dictionary *_original, struct dictionary *_match);
int compare_stringpair(struct string_pair _original, struct string_pair _match);
struct string_pair * look_up_key(struct dictionary *_dictionary, char * _key);
struct string_pair * look_up_value(struct dictionary *_dictionary, char * _value);

#endif