#include <singly_linked_list.h>

#ifndef __STACK_H__
#define __STACK_H__

typedef SLinkedList Stack;

Stack *stack_create();

void *stack_head(Stack *s);

void stack_push(Stack *s, void *data);

void *stack_pop(Stack *s);

void stack_show(Stack *s);

void stack_free(Stack *s, void (*free_data)(void *));

#endif