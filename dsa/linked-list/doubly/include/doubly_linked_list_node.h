#ifndef __DOUBLY_LINKED_LIST_NODE_H__
#define __DOUBLY_LINKED_LIST_NODE_H__

typedef struct d_ll_node {
    void *data;
    struct d_ll_node *next;
    struct d_ll_node *prev;
} DLLNode;

DLLNode *dll_node_create(void *);

#endif