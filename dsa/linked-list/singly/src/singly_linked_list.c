#include <singly_linked_list.h>

SLinkedList *sll_create() {
    SLinkedList *new_list = (SLinkedList *)malloc(1 * sizeof(SLinkedList));
    if (new_list == NULL) {
        perror("Error allocating memory for linkedlist");
        return NULL;
    }

    new_list->head = NULL;
    new_list->len = 0;
    return new_list;
}

void sll_insert_at_beginning(SLinkedList *list, void *data) {
    if (!list)
        return;

    SLLNode *node = sll_node_create(data);

    if (!node)
        return;

    node->next = list->head;
    list->head = node;
    list->len++;
}

void sll_insert_at_index(SLinkedList *list, size_t index, void *data) {
    if (!list)
        return;

    SLLNode *node = sll_node_create(data);

    if (!node)
        return;

    if (index < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (index == 1) {
        sll_insert_at_beginning(list, data);
        return;
    }

    SLLNode *ptr = list->head;

    for (size_t i = 0; i < index - 1 && ptr != NULL; i++, ptr = ptr->next)
        ;

    if (ptr == NULL) {
        printf("Position out of bounds!\n");
        free(node);
        return;
    }

    node->next = ptr->next;
    ptr->next = node;
    list->len++;
}

void sll_insert_at_end(SLinkedList *list, void *data) {
    if (!list)
        return;

    SLLNode *node = sll_node_create(data);

    if (!node)
        return;

    SLLNode *ptr = list->head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = node;
    list->len++;
}

void *sll_get_element_at_index(SLinkedList *list, size_t index) {
    if (!list || index >= list->len)
        return NULL;

    SLLNode *ptr = list->head;

    for (size_t i = 0; i < index; i++)
        ptr = ptr->next;

    return ptr->data;
}

void *sll_delete_at_beginning(SLinkedList *list) {
    if (!list || !list->head)
        return NULL;

    SLLNode *head = list->head;
    void *data = head->data;
    list->head = list->head->next;
    list->len--;

    free(head);
    return data;
}

void *sll_delete_at_end(SLinkedList *list) {
    if (!list || !list->head)
        return NULL;

    if (!list->head->next) {
        return sll_delete_at_beginning(list);
    }

    SLLNode *ptr = list->head;

    while (ptr->next->next)
        ptr = ptr->next;

    void *data = ptr->next->data;
    free(ptr->next);
    ptr->next = NULL;

    return data;
}

void *sll_delete_at_index(SLinkedList *list, size_t index) {
    if (!list || !list->head)
        return NULL;

    if (list->len <= index)
        return NULL;

    if (index == list->len - 1)
        return sll_delete_at_end(list);

    if (index == 0)
        return sll_delete_at_beginning(list);

    SLLNode *ptr = list->head;

    for (int i = 0; i < index - 1; i++, ptr = ptr->next)
        ;

    SLLNode *del_node = ptr->next;
    void *data = del_node->data;

    ptr->next = del_node->next;
    free(del_node);

    return data;
}

void sll_free(SLinkedList *list, void (*free_data)(void *data)) {
    if (!list)
        return;

    SLLNode *curr = list->head;

    while (curr) {
        SLLNode *next = curr->next;
        free_data(curr->data);
        free(curr);
        curr = next;
    }

    free(list);
}

void sll_display(SLinkedList *list) {
    SLLNode *ptr = list->head;

    while (ptr) {
        printf("%d ", *(int *)ptr->data);
        ptr = ptr->next;

        if (ptr) {
            printf("-> ");
        }
    }

    printf("\n");
}