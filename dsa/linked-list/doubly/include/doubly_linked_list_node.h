#ifndef __DOUBLY_LINKED_LIST_NODE_H__
#define __DOUBLY_LINKED_LIST_NODE_H__

typedef struct dll_node {
    void *data;
    struct dll_node *next;
    struct dll_node *prev;
} DLLNode;

DLLNode *dll_node_create(void *);

#endif