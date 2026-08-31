#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
typedef struct {
    int key;
    int index;
    int used;
} Entry;

void init(Entry *tab, int tsize){
    for (int i = 0; i < tsize; i++)
        tab[i].used = 0;
}

unsigned long hash(int key){
    uint32_t h = (uint32_t)key;
    h ^= h >> 16;
    h *= 0x7feb352dU;
    h ^= h >> 15;
    h *= 0x846ca68bU;
    h ^= h >> 16;
   return h;
}

unsigned long find(Entry *tab, int size, int key){
    unsigned long h = hash(key) % size;
    while (tab[h].used){
        if (tab[h].key == key)
            break;
        h = (h + 1) % size;
    }
    return h;
}

int get(Entry *tab, int tsize, int key, int *indx){
    unsigned long h = find(tab, tsize, key);
    if (!tab[h].used)
        return 0;
    *indx = tab[h].index;
    return 1;
}


void insert(Entry *tab, int tsize, int key, int index){
    unsigned long h = find(tab, tsize, key);
    if (!tab[h].used)
        tab[h].key = key, tab[h].used = 1, tab[h].index = index;
}

int longestConsecutive(int* nums, int numsSize) {
    if (!numsSize) return 0;
    int tsize = numsSize * 4;
    Entry  *tab = malloc(tsize * sizeof(Entry));
    if (!tab)
        return 0;
    init(tab, tsize);
    for (int i = 0; i < numsSize; i++)
        insert(tab, tsize, nums[i], i);
    int max = 1;
    for (int i = 0; i < numsSize; i++){
        int indx;
        if(get(tab, tsize, nums[i], &indx) && indx != i)
            continue;
        if(get(tab, tsize, nums[i] - 1, &indx))
            continue;
        int count = 1;
        int next = nums[i] + 1;
        while (count < numsSize) {
            int next;
            if (nums[i] > INT_MAX - count)
                break;
            next = nums[i] + count;
            if (!get(tab, tsize, next, &indx))
                break;
            count++;
        }
        if (count > max)
            max = count;
    }
    free(tab);
    return max;
}
#include <stdio.h>
int main(){
    int nums[] = {3, 9, 6, 2, 4, 7, 5};
    int size = sizeof(nums) / sizeof(int);
    printf("and our longet consicutive is : %d\n", longestConsecutive(nums, size));
}
