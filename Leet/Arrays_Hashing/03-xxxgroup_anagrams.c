#include<string.h>
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
}
