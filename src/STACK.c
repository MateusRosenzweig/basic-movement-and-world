#include "STACK.h"

struct pos{
    int x;
    int y;
};

struct node{

    struct node *next;
    Pos coord;

};

struct stack{

    Node *top;
    size_t size;

};

Stack* create_stack(void){

    Stack *new = malloc(sizeof(Stack));
    new->top = NULL;
    new->size = 0;

    return new;

}

size_t stack_size(Stack *p){
    return p->size;

}

void push_stack(Stack *p, int x, int y){
    Node *new = malloc(sizeof(Node));
    new->coord.x = x;
    new->coord.y = y;

    new->next = p->top;
    p->top = new;

    p->size += 1;

}

void pop_stack(Stack *p){
    Node *temp = p->top;

    p->top = p->top->next;
    free(temp);

    p->size -= 1;


}

void free_stack(Stack *p){

    while(p->top != NULL){
        pop_stack(p);
    }

    free(p);
    p = NULL;
}
