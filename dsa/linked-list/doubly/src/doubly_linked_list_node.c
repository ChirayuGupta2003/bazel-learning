#include "doubly_linked_list_node.h"
#include <stdio.h>
#include <stdlib.h>

DLLNode *dll_node_create(void *data) {
    DLLNode *new_node = (DLLNode *)malloc(sizeof(DLLNode));
    if (new_node == NULL) {
        perror("Error allocating memory for node");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
