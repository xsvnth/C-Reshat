#ifndef FLOATSTACK_H
#define FLOATSTACK_H


#include <stdlib.h>

typedef struct s_Stack {
    float *data;
    int top;
    int capacity;
} t_Stack;

t_Stack *stackCreate(){
    t_Stack *obj = malloc(sizeof(t_Stack));
    obj->capacity = 1;
    obj->data =  malloc(sizeof(float) * obj->capacity);
    obj->top = -1;
    return obj;
}

void Push(t_Stack *obj, float val) {
    if (obj->top + 1 == obj->capacity){
        obj->capacity *= 2;
        obj->data = realloc(obj->data, sizeof(float) * obj->capacity);
    }
    obj->data[++obj->top] = val;
}

int isEmpty(t_Stack *obj){
    return (obj->top == -1);
}

float Top(t_Stack *obj){
    return (obj->data[obj->top]);
}


#endif
