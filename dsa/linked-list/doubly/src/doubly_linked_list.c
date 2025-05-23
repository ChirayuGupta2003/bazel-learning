#include "doubly_linked_list.h"
#include "doubly_linked_list_node.h"
#include <stdio.h>
#include <stdlib.h>

DLinkedList *dll_create() {
    DLinkedList *new_list = (DLinkedList *)malloc(sizeof(DLinkedList));
    if (new_list == NULL) {
        perror("Error allocating memory for linkedlist");
        return NULL;
    }

    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->len = 0;
    return new_list;
}

void dll_insert_at_beginning(DLinkedList *list, void *data) {
    if (!list)
        return;

    DLLNode *node = dll_node_create(data);

    if (!node)
        return;

    node->next = list->head;
    if (list->head != NULL) {
        list->head->prev = node;
    }
    list->head = node;
    list->len++;

    if (list->tail == NULL) {
        list->tail = node;
    }
}

void dll_insert_at_end(DLinkedList *list, void *data) {
    if (!list)
        return;

    DLLNode *node = dll_node_create(data);

    if (!node)
        return;

    node->prev = list->tail;
    if (list->tail != NULL) {
        list->tail->next = node;
    }
    list->tail = node;
    list->len++;

    if (list->head == NULL) {
        list->head = node;
    }
}

void dll_insert_at_index(DLinkedList *list, size_t idx, void *data) {
    if (!list)
        return;

    if (idx > list->len) {
        return;
    }

    if (idx == 0) {
        dll_insert_at_beginning(list, data);
        return;
    }

    if (idx == list->len) {
        dll_insert_at_end(list, data);
        return;
    }

    DLLNode *node = dll_node_create(data);

    if (!node)
        return;

    if (idx < list->len / 2) {

        DLLNode *curr = list->head;

        for (size_t i = 0; i < idx - 1; i++) {
            curr = curr->next;
        }

        DLLNode *next = curr->next;

        curr->next = node;
        node->prev = curr;
        node->next = next;
        if (next != NULL) {
            next->prev = node;
        }
    } else {

        DLLNode *curr = list->tail;

        for (size_t i = list->len - 1; i > idx; i++) {
            curr = curr->prev;
        }
        DLLNode *prev = curr->prev;

        curr->prev = node;
        node->next = curr;
        node->prev = prev;
        if (prev != NULL) {
            prev->next = node;
        }
    }

    list->len++;
}

void *dll_get_element_at_index(DLinkedList *list, size_t idx) {
    if (!list)
        return NULL;

    if (idx >= list->len) {
        fprintf(stderr, "Index out of bounds\n");
        return NULL;
    }

    DLLNode *curr;
    if (idx < list->len / 2) {
        curr = list->head;

        for (size_t i = 0; i < idx; i++) {
            curr = curr->next;
        }
    } else {
        curr = list->tail;

        for (size_t i = list->len - 1; i > idx; i--) {
            curr = curr->prev;
        }
    }

    return curr->data;
}

void *dll_delete_at_beginning(DLinkedList *list) {
    if (!list || !list->head)
        return NULL;

    DLLNode *head = list->head;
    void *data = head->data;

    list->head = head->next;

    if (list->head)
        list->head->prev = NULL;
    else
        list->tail = NULL; // List is now empty

    list->len--;
    free(head);
    return data;
}

void *dll_delete_at_end(DLinkedList *list) {
    if (!list)
        return NULL;

    DLLNode *tail = list->tail;
    void *data = tail->data;

    list->tail = tail->prev;

    if (list->tail)
        list->tail->next = NULL;
    else
        list->head = NULL; // list is now empty

    list->len--;
    free(tail);
    return data;
}

void *dll_delete_at_index(DLinkedList *list, size_t idx) {
    if (!list || idx >= list->len) {
        fprintf(stderr, "Index out of bounds\n");
        return NULL;
    }

    if (idx == 0)
        return dll_delete_at_beginning(list);
    if (idx == list->len - 1)
        return dll_delete_at_end(list);

    DLLNode *curr;
    if (idx < list->len / 2) {
        curr = list->head;
        for (size_t i = 0; i < idx; i++)
            curr = curr->next;
    } else {
        curr = list->tail;
        for (size_t i = list->len - 1; i > idx; i--)
            curr = curr->prev;
    }

    void *data = curr->data;

    if (curr->prev)
        curr->prev->next = curr->next;
    if (curr->next)
        curr->next->prev = curr->prev;

    free(curr);
    list->len--;

    return data;
}

void dll_display(DLinkedList *list, void (*print_data)(void *)) {
    if (!list || !print_data)
        return;

    DLLNode *curr = list->head;

    while (curr) {
        print_data(curr->data);

        if (curr->next) {
            printf(" <-> ");
        }

        curr = curr->next;
    }

    printf("\n");
}

void dll_free(DLinkedList *list, void (*free_data)(void *data)) {
    if (!list)
        return;

    DLLNode *curr = list->head;

    while (curr) {
        DLLNode *next = curr->next;
        free_data(curr->data);
        free(curr);
        curr = next;
    }

    free(list);
}