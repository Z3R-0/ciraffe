#include <stdio.h>
#include <stdlib.h>

#include "structures.h"

#define FALSE 0
#define TRUE 1

/// Creates an empty dictionary
struct dictionary create_dictionary() {
    struct dictionary _dictionary;
    malloc(sizeof(&_dictionary));

    return _dictionary;
}

// Frees all memory held by provided dictionary
void destroy_dictionary(struct dictionary *_dictionary) {
    for(int i = 0;i < _dictionary->size;i++){
        free(_dictionary->nodes[i].this.key);
        free(_dictionary->nodes[i].this.value);
    }

    free(_dictionary->nodes);
    free(_dictionary);
}

/// Adds a node to the given dictionary using provided key and value
void add_node(struct dictionary _dictionary, char *key, char *value) {
    struct string_pair new_pair;

    malloc(sizeof(new_pair));

    new_pair.key = *key;
    new_pair.value = *value;

    struct node new_node = { new_node.this = new_pair };

    _dictionary.size++;
    realloc(&_dictionary, sizeof(_dictionary));

    _dictionary.nodes[_dictionary.size-1] = new_node;

    if(_dictionary.size >= 2)
        _dictionary.nodes[_dictionary.size-2].next = new_node;
}

/// Removes the first elemtent that mathes node_to_remove
void remove_node(struct dictionary _dictionary, struct node node_to_remove) {
    for(int i = 0; i < _dictionary.size; i++) {
        if(compare_node(_dictionary.nodes[i], node_to_remove) == TRUE) {
            _dictionary.nodes[i-1].next = _dictionary.nodes[i+1];

            free(_dictionary.nodes[i].this.key);
            free(_dictionary.nodes[i].this.value);

            return;
        }
    }
}

/// Compares all values of two dictionaries
int compare_dictionary(struct dictionary _original, struct dictionary _match) {
    if(_original.size != _match.size)
        return FALSE;
    
    for(int i = 0; i < _match.size; i++) {
        if(!(_original.nodes[i].this.key == _match.nodes[i].this.key && _original.nodes[i].this.value == _original.nodes[i].this.value
        && _original.nodes[i].next.key == _match.nodes[i].next.key && _original.nodes[i].next.value == _match.nodes[i].next.value))
        return FALSE;
    }

    return TRUE;
}

/// Compares all values of two nodes
int compare_node(struct node _original, struct node _match) {
    if(_original.this.key == _match.this.key && _original.this.value == _original.this.value
        && _original.next.key == _match.next.key && _original.next.value == _match.next.value)
        return TRUE;
    else 
        return FALSE;
}