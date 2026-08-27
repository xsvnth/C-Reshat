int peakfinder(int *r, int n){
    int first = 0, last = n - 1;
    while (first < last){
        int mid = first + (last - first) / 2;
        if (r[mid] < r[mid + 1])
            first = mid + 1;
        else 
            last = mid;
    }
    return r[first];
}
#include <stdio.h>
int main(){
    int r[] = {6, 7, 4, 3, 3, 2, 1, 4, 5};
    int n = sizeof(r) / sizeof(int);
    printf("%d\n", peakfinder(r, n));
}
