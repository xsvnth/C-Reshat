/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
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
}
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
