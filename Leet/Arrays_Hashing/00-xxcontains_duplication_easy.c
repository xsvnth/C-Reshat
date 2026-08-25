#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    int index;
    int used;
} Entry;

void init(Entry *tab, int size) {
    for (int i = 0; i < size; i++)
        tab[i].used = 0;
}

unsigned long hash(char *s){
    unsigned long h = 5381;
    while (*s)
        h = h * 33 + (unsigned char)*s++;
    return h;
}

unsigned long find(Entry *tab, int size, char *key){
    unsigned long h = hash(key) % size;
    while (tab[h].used){
        if (!strcmp(tab[h].key, key))
            break;
        h = (h + 1) % size;
    }
    return h;
}

int contains(Entry *tab, int size, char *key){
    unsigned long h = find(tab, size, key);
    if (!tab[h].used)
        return 0;
    return 1;
}

void insert(Entry *tab, int size, char *key, int idx){
    unsigned long h = find(tab, size, key);
    if(!tab[h].used)
        tab[h].key = key, tab[h].used = 1, tab[h].index = idx;
}

bool containsdup(int *nums, int nsize){
    int size = nsize * 2 + 1;
    Entry *tab = malloc(sizeof(Entry) * size);
    init(tab, size);
    char kbuf[12];
    for (int i = 0; i < nsize; i++){
        sprintf(kbuf, "%d", nums[i]);
        if(contains(tab, size, kbuf)){
            free (tab);
            return true;
        }
        insert(tab, size, strdup(kbuf), nums[i]);
    }
    free (tab);
    return false;
}

int main(){
    int nums[] = {1, 0, 9, 2, 8, 3, 4, 0};
    int size = sizeof(nums) / sizeof(int);
    printf("res = %b\n", containsdup(nums, size));
}
