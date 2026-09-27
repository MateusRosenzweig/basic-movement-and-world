#ifndef STACK_H
#define STACK_H

#include <stdlib.h>


typedef struct pos Pos;
typedef struct node Node;
typedef struct stack Stack;

Stack* create_stack(void);

size_t stack_size(Stack *p);

void push_stack(Stack *p, int x, int y);

void pop_stack(Stack *p);

void free_stack(Stack *p);

#endif
