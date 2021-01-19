#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "structures.h"

#define FALSE 0
#define TRUE 1

/// Creates an empty dictionary
struct dictionary * create_dictionary() {
    struct dictionary *_dictionary = malloc(sizeof(&_dictionary));

    _dictionary->size = 0;
    _dictionary->nodes = NULL;

    return _dictionary;
}


void print_dictionary(struct dictionary _dictionary) {
    for(int i = 0; i < _dictionary.size; i++) {
        printf("Entry %d: ", i);
        printf("key = %s | ", _dictionary.nodes[i].this.key);
        printf("value = %s | ", _dictionary.nodes[i].this.value);
        printf("next = %p\n", (void *) _dictionary.nodes[i].next);
    }
}

// Frees all memory held by provided dictionary
void free_dictionary(struct dictionary *_dictionary) {
    for(int i = 0; i < _dictionary->size; i++) {
        free(_dictionary->nodes->next);
    }
    
    free(_dictionary->nodes);
    free(_dictionary);

    _dictionary = NULL;
    assert(_dictionary == NULL);
}


/// Adds a node to the given dictionary using provided key and value
struct dictionary add_node(struct dictionary _dictionary, char *key, char *value) {
    struct string_pair new_pair;

    char *_key = malloc(sizeof(key));
    _key = key;
    char *_value = malloc(sizeof(value));
    _value = value;
    
    new_pair.key = _key;
    new_pair.value = _value;

    struct node new_node = { new_node.this = new_pair };

    _dictionary.size++;

    if(_dictionary.size > 1) {
        _dictionary.nodes = realloc(_dictionary.nodes, sizeof(struct node) * _dictionary.size);
    } else {
        _dictionary.nodes = malloc(sizeof(struct node) * _dictionary.size);
        if(_dictionary.nodes == NULL) {
            printf("Could not allocate memory for adding a new node\n");
        }
    }

    _dictionary.nodes[_dictionary.size - 1] = new_node;

    if(_dictionary.size >= 1) {
        _dictionary.nodes[_dictionary.size-1].next = &_dictionary.nodes[_dictionary.size];
    }
    
    return _dictionary;
}

/// Removes the first elemtent that mathes node_to_remove
struct dictionary remove_node(struct dictionary _dictionary, struct node node_to_remove) {
    for(int i = 0; i < _dictionary.size; i++) {
        if(compare_node(_dictionary.nodes[i], node_to_remove) == TRUE) {
            _dictionary.nodes[i-1].next = &_dictionary.nodes[i+1];

            return _dictionary;
        }
    }
}

/// Compares all values of two dictionaries
int compare_dictionary(struct dictionary _original, struct dictionary _match) {
    if(_original.size != _match.size)
        return FALSE;
    
    for(int i = 0; i < _match.size; i++) {
        if(!(_original.nodes[i].this.key == _match.nodes[i].this.key && _original.nodes[i].this.value == _original.nodes[i].this.value
        && _original.nodes[i].next->this.key == _match.nodes[i].next->this.key && _original.nodes[i].next->this.value == _match.nodes[i].next->this.value))
        return FALSE;
    }

    return TRUE;
}

/// Compares all values of two nodes
int compare_node(struct node _original, struct node _match) {
    if(_original.this.key == _match.this.key && _original.this.value == _original.this.value
        && _original.next->this.key == _match.next->this.key && _original.next->this.value == _match.next->this.value)
        return TRUE;
    else 
        return FALSE;
}

struct node * look_up_internal(struct dictionary _dictionary, char * _string){
    for(int i = 0; i < _dictionary.size; i++) {
        if(_dictionary.nodes[i].this.key == _string || _dictionary.nodes[i].this.value == _string) {
            return &_dictionary.nodes[i];
        }
    }

    return NULL;
}

/// Used to look up a key within a given dictionary
struct node * look_up_key(struct dictionary _dictionary, char * _key) {
    return look_up_internal(_dictionary, _key);
}

// Used to look up a value within a given dictionary
struct node * look_up_value(struct dictionary _dictionary, char * _value) {
    return look_up_internal(_dictionary, _value);
}
