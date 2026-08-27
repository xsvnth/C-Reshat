int peakfinder(int *r, int n){
    int right = 0, left = n - 1;
    while (left < right){
        int mid = left + (right - left) / 2;
        if (r[mid] < r[mid + 1])
            left = mid + 1;
        else 
            right = mid;
    }
    return r[left];
}
    /*------int i = n / 2;
    if (r[i] >= r[i - 1] && r[i] >= r[i + 1])
            return r[i];
    if (r[i] >= r[i - 1] && r[i] < r[i + 1]){
        while (i < n){
            if (r[i] >= r[i + 1])
                return r[i];
            i++;
        }
    }
    else if (r[i] >= r[i + 1] && r[i] < r[i - 1]){
        while (i){
            if (r[i] >= r[i - 1])
                return r[i];
            i--;
        }

    }
    return 0;
}-------------------*/
/*--------------------------else{
        while (i){

            i++;
        }
    }

        if (r[i] >= r[i + 1])
            return r[i];
        else { 
            if (i == n){
                return r[i];
            }
            i++;
        }
    }
    else if (r[i] >= r[i + 1]){
        if (r[i] >= r[i - 1])
            return r[i];
        else 
            if (i == n)
                return r[i];
            i--;
    }*/

#include <stdio.h>
int main(){
    int r[] = {6, 7, 4, 3, 2, 1, 4, 5};
    int n = sizeof(r) / sizeof(int);
    printf("%d\n", peakfinder(r, n));
}
