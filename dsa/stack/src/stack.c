#include "stack.h"
#include "singly_linked_list.h"
#include <stdlib.h>

Stack *stack_create() {
    Stack *s = (Stack *)sll_create();
    return s;
}

void *stack_head(Stack *s) {
    return sll_get_element_at_index((SLinkedList *)s, 0);
}

void stack_push(Stack *s, void *data) {
    return sll_insert_at_beginning((SLinkedList *)s, data);
}

void *stack_pop(Stack *s) { return sll_delete_at_beginning((SLinkedList *)s); }

void stack_show(Stack *s) {
    SLinkedList *list = (SLinkedList *)s;

    int **arr = (int **)sll_to_array(list);

    for (size_t i = 0; i < list->len; i++) {
        printf("%lu: %d\n", i, *arr[i]);
    }
}

void stack_free(Stack *s, void (*free_data)(void *)) {
    sll_free((SLinkedList *)s, free_data);
}