#include <string.h>
#include <stdlib.h>
char *encode(char **list, int lsize){
    int total = 1;
    for (int i = 0; i < lsize; i++){
        int len = strlen(list[i]);
        total += strlen(list[i]) + 2;
        if(len > 9)
            total++;
        if(len > 99)
            total++;
    }

    char *encoded = malloc(total);
    int k = 0;
    for (int i = 0; i < lsize; i++){
        int len = strlen(list[i]);
        if(len > 9)
            encoded[k++] = ((len / 10) % 10) + '0';
        if(len > 99)
            encoded[k++] = (len / 100) + '0';
        encoded[k++] = (len % 10) + '0';
        encoded[k++] = '#';
        for (int j = 0; j < len; j++)
            encoded[k++] = list[i][j];
    }
    encoded[k] = '\0';
    return encoded;
}

char **decode(char *encoded){
    int esize[100], words = 0, k = 0, x = 0; 
    while (encoded[k]){
        int len = 0;
        while (encoded[k] >= '0' && encoded[k] <= '9'){
            len = len * 10 + (encoded[k] - '0');
            k++;
        }
        esize[x++] = len;
        words++;
        k++;
        k += len;
    }
    char **decoded = malloc(sizeof(char *) * words);
    k = 0;
    for (int i = 0; i < words; i++){
        int len = 0;
        while (encoded[k] >= '0' && encoded[k] <= '9'){
            len = len * 10 + (encoded[k] - '0');
            k++;
        }
        k++;
        decoded[i] = malloc(sizeof(char) * (len + 1));
        for (int j = 0; j < len; j++)
            decoded[i][j] = encoded[k++];
        decoded[i][esize[i]] = '\0';
    }
    return decoded;
}
#include <stdio.h>
int main() {
    char *list[] = {"prazima do braziw", "conpirsaw con hazada"};
    int lsize = 2;
    char *encoded = encode(list, lsize);
    printf("%s\n", encoded);
    char **decoded = decode(encoded);
    printf("[");
    for(int i = 0; i < lsize; i++)
        printf("\"%s\", ", decoded[i]);
    printf("\b\b]\n");
}
