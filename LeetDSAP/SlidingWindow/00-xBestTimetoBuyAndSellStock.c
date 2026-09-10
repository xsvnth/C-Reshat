int maxProfit(int *prices, int psize){
    int smax = 0, bmin = *prices;
    for (int i = 0; i < psize; i++){
        if (prices[i] < bmin)
            bmin = prices[i];
        if (prices[i] - bmin > smax)
            smax = prices[i] - bmin;
    }
    return smax;
}
#include <stdio.h>
int main(){
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(int);
    printf("%d\n", maxProfit(prices, size));
}
