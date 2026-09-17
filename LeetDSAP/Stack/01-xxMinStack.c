#include <stdlib.h>
typedef struct s_MinStack {
    int *data;
    int *min;
    int top;
    int capacity;
}   t_MinStack;

t_MinStack *minStackCreate() {
    t_MinStack *stack = malloc(sizeof(t_MinStack));
    stack->capacity = 1, stack->top = -1;
    stack->data = malloc(sizeof(int) * stack->capacity); 
    stack->min = malloc(sizeof(int) * stack->capacity);
    return stack;
} 

void Push(t_MinStack *stack, int val){
    if (stack->top + 1 == stack->capacity){
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * sizeof(int));
        stack->min = realloc(stack->min, stack->capacity * sizeof(int));
    }
    stack->data[++stack->top] = val;
    if (!stack->top || val < stack->min[stack->top - 1])
        stack->min[stack->top] = val;
    else
        stack->min[stack->top] = stack->min[stack->top - 1];
}

void Pop(t_MinStack *stack){
    stack->top--;
}

int Top(t_MinStack *stack){
    return stack->data[stack->top];
}

int getMin(t_MinStack *stack){
    return stack->min[stack->top];
}

void minStackFree(t_MinStack *stack){
    free (stack->data);
    free (stack->min);
    free (stack);
}
#include <stdio.h>
int main(){
    t_MinStack *s = minStackCreate();

    Push(s, 2);
    Push(s, 5);
    Push(s, -5);
    Push(s, 2);
    Push(s, -5);
    Push(s, 8);

    printf("top = %d | min = %d\n",
        Top(s), getMin(s));

    Pop(s);
    Pop(s);

    printf("top = %d | min = %d\n",
        Top(s), getMin(s));

    Pop(s);
    Pop(s);

    printf("top = %d | min = %d\n",
        Top(s), getMin(s));

    minStackFree(s);
}
