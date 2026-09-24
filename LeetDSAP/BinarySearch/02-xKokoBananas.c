int KokoBananas(int *piles, int psize, int h) {
    int left = 1, right = 0;
    for (int i = 0; i < psize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }
    while (left <= right) {
        int k = left + (right - left) / 2;
        long long hours = 0;
        for (int i = 0; i < psize; i++) {
            hours += piles[i] / k;
            if (piles[i] % k)
                hours++;
        }
        if (hours > h)
            left = k + 1;
        else 
            right = k - 1;
    }
    return left;
}
#include <stdio.h>
int main(){
    int piles[] = {30, 11, 23, 4, 20};
    int size = sizeof(piles) / sizeof(int);
    printf("%d\n", KokoBananas(piles, size, 6));
}
