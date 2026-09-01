/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include "hashstr.h"

int cmpchar(const void *a, const void *b){
    return (*(char *)a - *(char *)b);
}

char *sorted_key(char *s){
    char *k = strdup(s);
    qsort(k, strlen(k), sizeof(char), cmpchar);
    return k;
}

char ***groupAnagrams(char **strs, int strsSize,
        int *returnSize, int **returnColumnSizes){
    char ***res = malloc(strsSize * sizeof(*res));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    Entry tab[strsSize * 2];
    init(tab, strsSize * 2);
    int groups = 0;

    for (int i = 0; i < strsSize; i++)
    {
        char *key = sorted_key(strs[i]);
        //printf("%s\n", key);
        int gid;
        if (get(tab, strsSize * 2, key, &gid)){
            int size = (*returnColumnSizes)[gid];
            res[gid] = realloc(res[gid], (size + 1) * sizeof(char *));
            res[gid][size] = strs[i];
            (*returnColumnSizes)[gid]++;
        }
        else{
            insert(tab, strsSize * 2, key, groups);
            res[groups] = malloc(sizeof(char *));
            res[groups][0] = strs[i];
            (*returnColumnSizes)[groups] = 1;
            groups++;
        }
    }
    *returnSize = groups;
    return res;
}
int main(){
    char *srs[] = {"abc", "silent", "cab", "listen", "telins"};
    int returnSize;
    int *returnColumnSizes;
    int strsize = sizeof(srs) / sizeof(srs[0]);
    char ***ret = groupAnagrams(srs, strsize, &returnSize, &returnColumnSizes);
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
/*I--------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int anagram(char *s1, char *s2){
    int hash[256] = {0};
    if(strlen(s1) != strlen(s2))
        return 0;
    while (*s1)
        hash[(unsigned char)*s1++]++, hash[(unsigned char)*s2++]--;
    for(int i  = 0; i < 256; i++){
        if(hash[i])
            return 0;
    }
    return 1;
}
char ***groupAnagrams(char **strs, int strsSize,
        int *returnSize, int **returnColumnSizes){
    char ***res = malloc(strsSize * sizeof(char **));
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    int groups = 0;
    for(int i = 0; i < strsSize; i++){
        int found = 0;
        //check every exist grp
        for(int j = 0; j < groups; j++){
            if(anagram(strs[i], res[j][0])){
                int size = (*returnColumnSizes)[j];
                res[j] = realloc(res[j], (size + 1) * sizeof(char *));
                res[j][size] = strs[i];
                (*returnColumnSizes)[j]++;
                found = 1;
                break;
            }
        }
        //no grp fnd -> create new one
        if (!found){
            res[groups] = malloc(sizeof(char *));
            res[groups][0] = strs[i];
            (*returnColumnSizes)[groups] = 1;
            groups++;
        }
    }
    *returnSize = groups;
    return res;
}---------------------------------------------------------------------------

II -------------------------------------------------------------------------
#include <stdlib.h>
#include <string.h>
#include "hashstr.h"

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
}---------------------------------------------------------------------------

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
}--------------------------------------------------------------------------*/
