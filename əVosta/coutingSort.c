void countingSort(int *arr, int size) {
    int max = arr[0], i, k = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    int counter[max + 1];
    for (i = 0; i <= max; i++)
        counter[i] = 0;
    for (i = 0; i < size; i++)
        counter[arr[i]]++;
    for (i = 0; i <= max; i++) {
        while (counter[i]--)
            arr[k++] = i;
    }
}
#include <stdio.h>
int main() {
    int arr[] = {19843, 20023, 3314, 22324, 11244, 2435, 35365, 100132, 41410};
    int size = sizeof(arr) / sizeof(int);
    countingSort(arr, size);
    printf("[");
    for (int i = 0; i < size; i++) 
        printf("%d, ", arr[i]);
    printf("\b\b]\n");
}
