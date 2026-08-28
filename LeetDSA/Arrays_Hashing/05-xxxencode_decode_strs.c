#include <string.h>
char *encode(char **list, int lsize, char *esize, int words){
    char *encoded;
    int count = 0;
    char buf[64];
    int k = 0;
    for (int i = 0; i < lsize; i++){
        for (int j = 0; j < strlen(list[i]); j++){
            encoded[j] = list[i][j];
            if (list[i][j] == '\0')
                buf[k++] = j, count++;
        }
    }
    words = count;
    esize = buf;
    return encoded;
}

#include <stdio.h>
int main(){
    char *list[] = {"prazima", "conpirsaw"};
    int lsize = 2, words;
    char each;
    char *encoded = encode(list, lsize, &each, words);
    printf("%s\n", encoded);
    printf("[");
    for(int i = 0; i < lsize; i++)
        printf("%s, ", decode(encoded[i]));
    printf("\b\b]\n");
}
