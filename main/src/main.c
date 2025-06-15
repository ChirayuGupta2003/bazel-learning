#include <doubly_linked_list.h>
#include <singly_linked_list.h>
#include <stack.h>
#include <stdio.h>
#include <stdlib.h>

void print_int(void *data) { printf("%d", *(int *)data); }

void no_op(void *data) { return; }

int main(int argc, char *argv[]) {

    printf(
        "###################### Singly Linked List ######################\n");

    SLinkedList *sll_list = sll_create();

    if (!sll_list) {
        printf("Error creating linked sll_list\n");
        return -1;
    }

    printf("Created linked sll_list\n\n");

    int num1 = 10;
    int num2 = 20;
    int num3 = 30;
    int num4 = 100;

    sll_insert_at_beginning(sll_list, &num1);
    printf("Inserted %d at beginning\n", num1);
    sll_display(sll_list, print_int);
    printf("Head data: ");
    print_int(sll_list->head->data);
    printf("\nsll_list size: %lu\n", sll_list->len);
    printf("\n");
    printf("\n");

    sll_insert_at_beginning(sll_list, &num2);
    printf("Inserted %d at beginning\n", num2);
    sll_display(sll_list, print_int);
    printf("Head data: ");
    print_int(sll_list->head->data);
    printf("\nsll_list size: %lu\n", sll_list->len);
    printf("\n");
    printf("\n");

    sll_insert_at_end(sll_list, &num3);
    printf("Inserted %d at end\n", num3);
    sll_display(sll_list, print_int);
    printf("Head data: ");
    print_int(sll_list->head->data);
    printf("\nsll_list size: %lu\n", sll_list->len);
    printf("\n");
    printf("\n");

    size_t idx = 2;
    sll_insert_at_index(sll_list, idx, &num4);
    printf("Inserted %d at index %zu\n", num4, idx);
    sll_display(sll_list, print_int);
    printf("Head data: ");
    print_int(sll_list->head->data);
    printf("\nsll_list size: %lu\n", sll_list->len);
    printf("\n");
    printf("\n");

    printf("Deleted at beginning is %d\n",
           *(int *)sll_delete_at_beginning(sll_list));
    sll_display(sll_list, print_int);
    printf("Head data: ");
    print_int(sll_list->head->data);
    printf("\nsll_list size: %lu\n", sll_list->len);
    printf("\n");
    printf("\n");

    printf("Deleted at end is %d\n", *(int *)sll_delete_at_end(sll_list));
    sll_display(sll_list, print_int);
    printf("Head data: ");
    print_int(sll_list->head->data);
    printf("\nsll_list size: %lu\n", sll_list->len);
    printf("\n");
    printf("\n");

    sll_free(sll_list, no_op);

    printf("\n###################### Doubly Linked List "
           "######################\n\n");

    DLinkedList *dll_list = dll_create();

    if (!dll_list) {
        printf("Error creating linked list\n");
        return -1;
    }

    printf("Created linked list\n\n");

    dll_insert_at_beginning(dll_list, &num1);
    printf("Inserted %d at beginning\n", num1);
    dll_display(dll_list, print_int);
    printf("Head data: ");
    print_int(dll_list->head->data);
    printf("\nTail data: ");
    print_int(dll_list->tail->data);
    printf("\ndll_list size: %lu\n", dll_list->len);
    printf("\n");
    printf("\n");

    dll_insert_at_beginning(dll_list, &num2);
    printf("Inserted %d at beginning\n", num2);
    dll_display(dll_list, print_int);
    printf("Head data: ");
    print_int(dll_list->head->data);
    printf("\nTail data: ");
    print_int(dll_list->tail->data);
    printf("\ndll_list size: %lu\n", dll_list->len);
    printf("\n");
    printf("\n");

    dll_insert_at_end(dll_list, &num3);
    printf("Inserted %d at end\n", num3);
    dll_display(dll_list, print_int);
    printf("Head data: ");
    print_int(dll_list->head->data);
    printf("\nTail data: ");
    print_int(dll_list->tail->data);
    printf("\ndll_list size: %lu\n", dll_list->len);
    printf("\n");
    printf("\n");

    dll_insert_at_index(dll_list, idx, &num4);
    printf("Inserted %d at index %zu\n", num4, idx);
    dll_display(dll_list, print_int);
    printf("Head data: ");
    print_int(dll_list->head->data);
    printf("\nTail data: ");
    print_int(dll_list->tail->data);
    printf("\ndll_list size: %lu\n", dll_list->len);
    printf("\n");
    printf("\n");

    printf("Deleted at beginning is %d\n",
           *(int *)dll_delete_at_beginning(dll_list));
    dll_display(dll_list, print_int);
    printf("Head data: ");
    print_int(dll_list->head->data);
    printf("\nTail data: ");
    print_int(dll_list->tail->data);
    printf("\ndll_list size: %lu\n", dll_list->len);
    printf("\n");
    printf("\n");

    printf("Deleted at end is %d\n", *(int *)dll_delete_at_end(dll_list));
    dll_display(dll_list, print_int);
    printf("Head data: ");
    print_int(dll_list->head->data);
    printf("\nTail data: ");
    print_int(dll_list->tail->data);
    printf("\ndll_list size: %lu\n", dll_list->len);
    printf("\n");
    printf("\n");

    dll_free(dll_list, no_op);

    printf("###################### Stack ######################\n\n");

    Stack *s = stack_create();
    int a = 10;
    int b = 20;

    printf("Pushing %d\n", a);
    stack_push(s, &a);
    stack_show(s);
    printf("Head data: %d\n", *(int *)stack_head(s));
    printf("\n");

    printf("Pushing %d\n", b);
    stack_push(s, &b);
    stack_show(s);
    printf("Head data: %d\n", *(int *)stack_head(s));
    printf("\n");

    int *x = stack_pop(s);
    printf("Popped %d\n", *x);
    stack_show(s);
    printf("Head data: %d\n", *(int *)stack_head(s));
    printf("\n");

    stack_free(s, no_op);

    return 0;
}
