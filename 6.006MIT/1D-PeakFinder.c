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
    int r[] = {12, 16, 10, 17, 13};
    int n = sizeof(r) / sizeof(int);
    printf("%d\n", peakfinder(r, n));
}
