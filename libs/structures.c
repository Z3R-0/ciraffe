#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "structures.h"

#define FALSE 0
#define TRUE 1

// Creates an empty dictionary
struct dictionary * create_dictionary() {
    struct dictionary *_dictionary = malloc(sizeof(struct dictionary));

    _dictionary->size = 0;
    _dictionary->string_pair = NULL;

    return _dictionary;
}


void print_dictionary(struct dictionary *_dictionary) {
    for(int i = 0; i < _dictionary->size; i++) {
        printf("Entry %d: ", i);
        printf("key = %s | ", _dictionary->string_pair[i].key);
        printf("value = %s | ", _dictionary->string_pair[i].value);
    }
}

// Frees all memory held by provided dictionary
void free_dictionary(struct dictionary *_dictionary) {
    for(int i = 0; i < _dictionary->size; i++) {
        free(&_dictionary->string_pair[i]);
    }
    free(_dictionary);

    _dictionary = NULL;
    assert(_dictionary == NULL);
}


/// Adds a node to the given dictionary using provided key and value
struct dictionary * add(struct dictionary *_dictionary, char *key, char *value) {
    struct string_pair *new_pair = malloc(sizeof(struct string_pair));
    
    new_pair->key = key;
    new_pair->value = value;

    _dictionary->size++;

    if(_dictionary->size > 1) {
        _dictionary->string_pair = realloc(_dictionary->string_pair, sizeof(struct string_pair) * _dictionary->size);
    } else {
        _dictionary->string_pair = malloc(sizeof(struct string_pair) * _dictionary->size);
        if(_dictionary->string_pair == NULL) {
            printf("Could not allocate memory for adding a new node\n");
        }
    }

    _dictionary->string_pair[_dictionary->size - 1] = *new_pair;
    
    return _dictionary;
}

/// Removes the first elemtent that mathes node_to_remove
struct dictionary * remove_stringpair(struct dictionary *_dictionary, char *key) {
    /* OLD IMPLEMENTATION
    for(int i = 0; i < _dictionary->size; i++) {
        if(compare_node(_dictionary->nodes[i], node_to_remove) == TRUE) {
            _dictionary->nodes[i-1].next = &_dictionary->nodes[i+1];

            return _dictionary;
        }
    }
    */

   // Wow this one kinda hard, figure it out later lmao

   for(int i = 0; i < _dictionary->size; i++) {
        if(_dictionary[i].string_pair->key == key) {
            
        }
    }
}

/// Compares all values of two dictionaries
int compare_dictionary(struct dictionary *_original, struct dictionary *_match) {
    if(_original->size != _match->size)
        return FALSE;
    
    for(int i = 0; i < _match->size; i++) {
        if(!(_original->string_pair[i].key == _match->string_pair[i].key && _original->string_pair[i].value == _original->string_pair[i].value))
            return FALSE;
    }

    return TRUE;
}

/// Compares all values of two nodes
int compare_stringpair(struct string_pair _original, struct string_pair _match) {
    if(_original.key == _match.key && _original.value == _original.value)
        return TRUE;
    else 
        return FALSE;
}

struct string_pair * look_up_internal(struct dictionary *_dictionary, char * _searchString){
    for(int i = 0; i < _dictionary->size; i++) {
        if(_dictionary->string_pair[i].key == _searchString || _dictionary->string_pair[i].value == _searchString) {
            return &_dictionary->string_pair[i];
        }
    }

    return NULL;
}

/// Used to look up a key within a given dictionary
struct string_pair * look_up_key(struct dictionary *_dictionary, char * _key) {
    return look_up_internal(_dictionary, _key);
}

// Used to look up a value within a given dictionary
struct string_pair * look_up_value(struct dictionary *_dictionary, char * _value) {
    return look_up_internal(_dictionary, _value);
}
