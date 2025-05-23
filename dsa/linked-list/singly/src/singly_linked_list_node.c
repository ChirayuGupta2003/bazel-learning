#include "singly_linked_list_node.h"

SLLNode *sll_node_create(void *data) {
    SLLNode *new_node = (SLLNode *)malloc(sizeof(SLLNode));
    if (new_node == NULL) {
        perror("Error allocating memory for node");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
