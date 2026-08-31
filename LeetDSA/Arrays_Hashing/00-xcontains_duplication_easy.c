#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    return ((*(int*)a > *(int*)b) - (*(int*)a < *(int*)b));
}

bool containsDuplicate(int *arr, int n){
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n - 1; i++)
        if (arr[i] == arr[i + 1])
            return true;
    return false;
}

int main(void)
{
    int arr[] = {1, 2, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", containsDuplicate(arr, n));
    return 0;
}
