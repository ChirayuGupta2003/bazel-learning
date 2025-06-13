#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack Stack;

Stack *stack_create();

void *stack_head(Stack *s);

void stack_push(Stack *s, void *data);

void *stack_pop(Stack *s);

#endif