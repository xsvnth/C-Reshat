int maxProfit(int *prices, int psize){
    int left = 0, maxP = 0;
    for (int right = 0; right < psize; right++){
        if (prices[left] < prices[right]) {
            if (prices[right] - prices[left] > maxP)
                maxP = prices[right] - prices[left];
        }
        else 
            left = right;
    }
    return maxP;
}
#include <stdio.h>
int main(){
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(int);
    printf("%d\n", maxProfit(prices, size));
}
