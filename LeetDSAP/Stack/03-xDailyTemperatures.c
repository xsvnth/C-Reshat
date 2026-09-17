#include "Stack.h"
int *dailyTemperatures(int* tmprtrs, int tSize, int* rSize) {
    int *ret = calloc(sizeof(int), tSize);
    t_Stack *obj = StackCreate();
    int i = 0;
    for (i = 0; i < tSize; i++){
        while (!isEmpty(obj) && tmprtrs[i] > tmprtrs[Top(obj)]){
            ret[Top(obj)] = i - Top(obj);
            Pop(obj);
        }
        Push(obj, i);
    }
    *rSize = i;
    return ret;
}
#include <stdio.h>
int main(){
    int tmprtrs[] = {73,74,75,71,69,72,76,73};
    int size = sizeof(tmprtrs) / sizeof(int);
    int rsize;
    int *ret = dailyTemperatures(tmprtrs, size, &rsize);
    printf("[");
    for (int i = 0; i < rsize; i++)
        printf("%d, ", ret[i]);
    printf("\b\b]\n");
}
