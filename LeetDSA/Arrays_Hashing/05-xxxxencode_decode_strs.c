#include <string.h>
#include <stdlib.h>
char *encode(char **list, int lsize){
    char *encoded = malloc(lsize * sizeof(char) + 2 * lsize);
    int count = 0;
    int buf[64];
    int k = 0;
    for (int i = 0; i < lsize; i++){
        for (int j = 0; j < strlen(list[i]); j++){
            if(j == 0)
                encoded[k++] = strlen(list[i]) + '0', encoded[k++] = '#';
            encoded[k++] = list[i][j];
        }
    }
    return encoded;
}

char **decode(char *encoded){
    int esize[100], words = 0, k = 0, x = 0; 
    while (encoded[k]){
        if (encoded[k] >= '0' && encoded[k] <= '9')
            esize[x++] = encoded[k] - '0';
        else if (encoded[k] == '#')
            words++;
        k++;
    }
    char **decoded = malloc(sizeof(char *) * words);
    k = 0;
    for (int i = 0; i < words; i++){
        decoded[i] = malloc(sizeof(char) * (esize[i] + 1));
        for (int j = 0; j < esize[i]; j++){
            while (encoded[k] == '#' 
                    || (encoded[k] >= '0' && encoded[k] <= '9'))
                k++;
            decoded[i][j] = encoded[k++];
        }
        decoded[i][esize[i]] = '\0';
    }
    return decoded;
}
#include <stdio.h>
int main() {
    char *list[] = {"prazima", "conpirsaw"};
    int lsize = 2;
    char *encoded = encode(list, lsize);
    printf("%s\n", encoded);
    char **decoded = decode(encoded);
    printf("[");
    for(int i = 0; i < lsize; i++)
        printf("%s, ", decoded[i]);
    printf("\b\b]\n");
}
