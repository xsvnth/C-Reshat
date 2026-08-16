#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool containsDuplicate(int *arr, int n)
{
    qsort(arr, n, sizeof(int), cmp);

    //int a[1024] = {0};
    for (int i = 1; i < n; i++)
    {
        //if (a[arr[i]])
            //a[arr[i]]--;
        //if (a[arr[i]])
        //    return true;
        /*a[arr[i]]++;

        if (a[arr[i]]>1)
            return true;*/
        if (arr[i] == arr[i - 1])
            return true;
    }
    return false;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, -1, 5, 6, 7, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", containsDuplicate(arr, n));
    return 0;
}
