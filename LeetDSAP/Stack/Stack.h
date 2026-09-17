#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct s_Stack {
    int *data;
    int top;
    int capacity;
}   t_Stack;

t_Stack *StackCreate() {
    t_Stack *stack = malloc(sizeof(t_Stack));
    if (!stack)
        return NULL;
    stack->capacity = 1, stack->top = -1;
    stack->data = malloc(sizeof(int) * stack->capacity);
    if (!stack->data) {
        free (stack);
        return NULL;
    }
    return stack;
} 

void Push(t_Stack *stack, int val){
    if (stack->top + 1 == stack->capacity){
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = val;
}

void Pop(t_Stack *stack){
    if (stack->top > -1)
        stack->top--;
}

int Top(t_Stack *stack){
    return stack->data[stack->top];
}

void StackFree(t_Stack *stack){
    if (!stack)
        return; 
    free (stack->data);
    free (stack);
}

int isEmpty(t_Stack *obj){
    return (obj->top == -1);
}

#endif
