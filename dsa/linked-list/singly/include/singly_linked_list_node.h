#include <stdio.h>
#include <stdlib.h>

#ifndef __SINGLY_LINKED_LIST_NODE_H__
#define __SINGLY_LINKED_LIST_NODE_H__

typedef struct s_ll_node {
    void *data;
    struct s_ll_node *next;
} SLLNode;

SLLNode *sll_node_create(void *);

#endif