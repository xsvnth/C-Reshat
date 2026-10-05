void quicksort(int *arr, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, k = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < k) i++;
        while (arr[j] > k) j--;
        if (i <= j) {
            int tmp = arr[i];
            arr[i++] = arr[j];
            arr[j--] = tmp;
        }
    }
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}
#include <stdio.h>
int main() {
    int arr[] = {14, 542, 2, 8765, 98643, 9, 0, 354, 543};
    int size = sizeof(arr) / sizeof(int);
    int left = 0, right = size - 1;
    quicksort(arr, left, right);
    printf("[");
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\b\b]\n");
}
