#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__

#include "singly_linked_list_node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_linked_list {
    SLLNode *head;
    size_t len;
} SLinkedList;

SLinkedList *sll_create();

void sll_insert_at_beginning(SLinkedList *list, void *data);

void sll_insert_at_index(SLinkedList *list, size_t idx, void *data);

void sll_insert_at_end(SLinkedList *list, void *data);

void *sll_get_element_at_index(SLinkedList *list, size_t idx);

void *sll_delete_at_beginning(SLinkedList *list);

void *sll_delete_at_end(SLinkedList *list);

void *sll_delete_at_index(SLinkedList *list, size_t idx);

void sll_free(SLinkedList *list, void (*free_data)(void *data));

void sll_display(SLinkedList *list, void (*print_data)(void *data));

void **sll_to_array(SLinkedList *list);

#endif