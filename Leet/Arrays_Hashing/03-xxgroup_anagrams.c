#include <stdlib.h>
#include <string.h>
#include "hash.h"

int cmpc(const void *a, const void *b){
    return *(unsigned char*)a - *(unsigned char*)b;
}

char ***groupAnagrams(char **strs, int strsSize,
        int *returnSize, int **returnColumnSizes){
    int size = strsSize * 2;
    Entry *tab = calloc(size, sizeof(Entry));
    char ***res = malloc(strsSize * sizeof(char **));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    int *cap = malloc(strsSize * sizeof(int));
    int groups = 0;

    for (int i = 0; i < strsSize; i++){
        int len = strlen(strs[i]);
        char *key = malloc(len + 1);
        memcpy(key, strs[i], len + 1);
        qsort(key, len, 1, cmpc);

        int h = find(tab, size, key); // your hash.h function

        if (!tab[h].used){
            // new group:
            int idx = groups++;
            tab[h].key = key;
            tab[h].used = 1;
            tab[h].index = idx; // storing groupIdx here

            cap[idx] = 4;
            (*returnColumnSizes)[idx] = 0;
            res[idx] = malloc(cap[idx] * sizeof(char *));
        } else {
            free(key); // already have this key stored, don't need the copy
        }

        int idx = tab[h].index;
        if ((*returnColumnSizes)[idx] == cap[idx]){
            cap[idx] *= 2;
            res[idx] = realloc(res[idx], cap[idx] * sizeof(char *));
        }
        res[idx][(*returnColumnSizes)[idx]++] = strs[i];
    }

    *returnSize = groups;

    for (int i = 0; i < size; i++)
        if (tab[i].used)
            free(tab[i].key);
    free(tab);
    free(cap);

    return res;
}

/*#include<string.h>
#include<stdlib.h>

typedef struct Node {
    char *key;
    int groupIdx;
    struct Node *next;
} Node;

#define TSIZE 20011

unsigned long hashkey(char *s){
    unsigned long h = 5381;
    while(*s) h = ((h<<5)+h) + (unsigned char)*s++;
    return h;
}

int cmpc(const void *a, const void *b){
    return *(unsigned char*)a - *(unsigned char*)b;
}

char ***groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Node *table[TSIZE] = {0};
    char ***res = malloc(strsSize * sizeof(char **));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    int *cap = malloc(strsSize * sizeof(int));
    int groups = 0;

    for (int i = 0; i < strsSize; i++){
        int len = strlen(strs[i]);
        char *key = malloc(len + 1);
        memcpy(key, strs[i], len + 1);
        qsort(key, len, 1, cmpc);

        unsigned long h = hashkey(key) % TSIZE;
        Node *n = table[h];
        int idx = -1;
        while(n){
            if(strcmp(n->key, key) == 0){ idx = n->groupIdx; break; }
            n = n->next;
        }
     //zaba fi itar l9owa wkda
        if(idx == -1){
            idx = groups++;
            cap[idx] = 4;
            (*returnColumnSizes)[idx] = 0;
            res[idx] = malloc(cap[idx] * sizeof(char *));

            Node *nn = malloc(sizeof(Node));
            nn->key = key;
            nn->groupIdx = idx;
            nn->next = table[h];
            table[h] = nn;
        } else {
            free(key);
        }

        if((*returnColumnSizes)[idx] == cap[idx]){
            cap[idx] *= 2;
            res[idx] = realloc(res[idx], cap[idx] * sizeof(char *));
        }
        res[idx][(*returnColumnSizes)[idx]++] = strs[i];
    }

    // shrink returnColumnSizes to actual groups count if needed by your caller
    *returnSize = groups;

    // free hash table
    for(int i = 0; i < TSIZE; i++){
        Node *n = table[i];
        while(n){ Node *nx = n->next; free(n->key); free(n); n = nx; }
    }
    free(cap);

    return res;
}*/
#include <stdio.h>

int main(){
    char *srs[] = {"abc", "silent", "cab", "listen", "telins"};
    int returnSize;
    int *returnColumnSizes;
    char ***ret = groupAnagrams(srs, 5, &returnSize, &returnColumnSizes);

    printf("[");
    for (int i = 0; i < returnSize; i++){
        printf(" [");
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%s", ret[i][j]);
            if (j + 1 < returnColumnSizes[i])
                printf(", ");
        }
        printf("] ");
    }
    printf("]\n");

    for(int i = 0; i < returnSize; i++)
        free(ret[i]);
    free(ret);
    free(returnColumnSizes);
    return 0;
}
