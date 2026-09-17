#include "floatStack.h"

typedef struct s_PScar {
    int position;
    int speed;
} t_PScar;

int cmp(const void *x, const void *y) {
    return (((t_PScar *)x)->position - ((t_PScar *)y)->position);
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    t_Stack *obj = stackCreate();
    t_PScar cars[positionSize];
    for (int i = 0; i < positionSize; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, positionSize, sizeof(t_PScar), cmp);
    for (int i = positionSize - 1; i > -1; i--){
        float timeToEnd = (float)(target - cars[i].position) / cars[i].speed;
        if (isEmpty(obj) || timeToEnd > Top(obj))
            Push(obj, timeToEnd);
    }
    return (obj->top + 1);
}

#include <stdio.h>
int main(){
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int pSize = sizeof(position) / sizeof(int);
    printf("%d\n", carFleet(100, position, pSize, speed, pSize));

}
