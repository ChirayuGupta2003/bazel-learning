#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__

#include "doubly_linked_list_node.h"
#include <stddef.h>

typedef struct {
    DLLNode *head;
    DLLNode *tail;
    size_t len;
} DLinkedList;

DLinkedList *dll_create();

void dll_insert_at_beginning(DLinkedList *list, void *data);

void dll_insert_at_index(DLinkedList *list, size_t idx, void *data);

void dll_insert_at_end(DLinkedList *list, void *data);

void *dll_get_element_at_index(DLinkedList *list, size_t idx);

void *dll_delete_at_beginning(DLinkedList *list);

void *dll_delete_at_end(DLinkedList *list);

void *dll_delete_at_index(DLinkedList *list, size_t idx);

void dll_free(DLinkedList *list, void (*free_data)(void *data));

void dll_display(DLinkedList *list, void (*print_data)(void *data));

#endif