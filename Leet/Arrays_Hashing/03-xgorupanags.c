#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{
    char *key;
    int used;
    int index;
} Entry;

unsigned long hash(char *s){
    unsigned long h = 5381;
    while(*s)
        h = h * 33 + (unsigned char)*s++;
    return h;
}

unsigned long find(Entry *tab, int size, char *key){
    unsigned long h = hash(key) % size;
    while(tab[h].used){
        if(!strcmp(tab[h].key, key))
            break;
        h = (h + 1) % size;
    }
    return h;
}

int get(Entry *tab, int size, char *key, int *ret){
    int h = find(tab, size, key);
    if (!tab[h].used)
        return 0;
    *ret = tab[h].index;
    return 1;
}

void init(Entry *tab, int size){
    for(int i = 0; i < size; i++)
        tab[i].used = 0;
}

int cmpchar(const void *a, const void *b){
    return (*(char *)a - *(char *)b);
}

char *sorted_key(char *s){
    char *k = strdup(s);
    qsort(k, strlen(k), sizeof(char), cmpchar);
    return k;
}

void insert(Entry *tab, int size, char *key, int index){
    int h = find(tab, size, key);
    if(!tab[h].used){
        tab[h].key = key;
        tab[h].used = 1;
    }
    tab[h].index = index;
}

char ***anagroup(char **strs, int strsize, int *retsize, int **retcols){
    char ***res = malloc(strsize * sizeof(*res));
    *retcols = malloc(strsize * sizeof(int));
    Entry tab[strsize * 2];
    init(tab, strsize * 2);
    int groups = 0;
    for (int i = 0; i < strsize; i++){
        char *key = sorted_key(strs[i]);
        int gid;
        if (get(tab, strsize * 2, key, &gid)){
            int size = (*retcols)[gid];
            res[gid] = realloc(res[gid], (size + 1) * sizeof(char *));
            res[gid][size] = strs[i];
            (*retcols)[gid]++;
        }
        else {
            insert(tab, strsize * 2, key, groups);
            res[groups] = malloc(sizeof(char *));
            res[groups][0] = strs[i];
            (*retcols)[groups] = 1;
            groups++;
        }
    }
    *retsize = groups;
    return res;
}
int main(){
    char *strs[] = {"cap", "pac", "silent", "acp", "listen", "telins"};
    int size = sizeof(strs) / sizeof(strs[0]);
    int *retcols;
    int retsize;
    char ***res = anagroup(strs, size, &retsize, &retcols);
    printf("[");
    for(int i = 0; i < retsize; i++){
        printf("[");
        for (int j = 0; j < retcols[i]; j++){
            printf("%s", res[i][j]);
            if(j + 1 < retcols[i])
                printf(", ");
        }
        printf("]");
    }
    printf("]\n");
    for (int i = 0; i < retsize; i++)
        free(res[i]);
    free(res);
    free(retcols);
    return 0;
}
