#include <doubly_linked_list.h>
#include "singly_linked_list.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void print_int(void *data) { printf("%d", *(int *)data); }

void no_op(void *data) { return; }

int main(int argc, char *argv[]) {

    // DLinkedList *list = dll_create();

    // if (!list) {
    //     printf("Error creating linked list\n");
    //     return -1;
    // }

    // printf("Created linked list\n\n");

    // int num1 = 10;
    // int num2 = 20;
    // int num3 = 30;
    // int num4 = 100;

    // dll_insert_at_beginning(list, &num1);
    // printf("Inserted %d at beginning\n", num1);
    // dll_display(list, print_int);
    // printf("Head data: ");
    // print_int(list->head->data);
    // printf("\nTail data: ");
    // print_int(list->tail->data);
    // printf("\nList size: %lu\n", list->len);
    // printf("\n");
    // printf("\n");

    // dll_insert_at_beginning(list, &num2);
    // printf("Inserted %d at beginning\n", num2);
    // dll_display(list, print_int);
    // printf("Head data: ");
    // print_int(list->head->data);
    // printf("\nTail data: ");
    // print_int(list->tail->data);
    // printf("\nList size: %lu\n", list->len);
    // printf("\n");
    // printf("\n");

    // dll_insert_at_end(list, &num3);
    // printf("Inserted %d at end\n", num3);
    // dll_display(list, print_int);
    // printf("Head data: ");
    // print_int(list->head->data);
    // printf("\nTail data: ");
    // print_int(list->tail->data);
    // printf("\nList size: %lu\n", list->len);
    // printf("\n");
    // printf("\n");

    // size_t idx = 2;
    // dll_insert_at_index(list, idx, &num4);
    // printf("Inserted %d at index %zu\n", num4, idx);
    // dll_display(list, print_int);
    // printf("Head data: ");
    // print_int(list->head->data);
    // printf("\nTail data: ");
    // print_int(list->tail->data);
    // printf("\nList size: %lu\n", list->len);
    // printf("\n");
    // printf("\n");

    // printf("Deleted at beginning is %d\n",
    //        *(int *)dll_delete_at_beginning(list));
    // dll_display(list, print_int);
    // printf("Head data: ");
    // print_int(list->head->data);
    // printf("\nTail data: ");
    // print_int(list->tail->data);
    // printf("\nList size: %lu\n", list->len);
    // printf("\n");
    // printf("\n");

    // printf("Deleted at end is %d\n", *(int *)dll_delete_at_end(list));
    // dll_display(list, print_int);
    // printf("Head data: ");
    // print_int(list->head->data);
    // printf("\nTail data: ");
    // print_int(list->tail->data);
    // printf("\nList size: %lu\n", list->len);
    // printf("\n");
    // printf("\n");

    // dll_free(list, no_op);

    Stack *s = stack_create();

    return 0;
}
