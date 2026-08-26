#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *encode(char **strs, int count){
    size_t tlen = 0;
    for (int i = 0; i < count; i++){
        int slen = strlen(strs[i]);
        char lbuf[12];
        int digits = snprintf(lbuf, sizeof(lbuf), "%d", slen);
        tlen += digits + 1 + slen;
    }
    char *encoded = malloc(tlen + 1); // +1 for null terminator
    encoded[0] = '\0';

    // 2. Second pass: actually write "<len>#<string>" for each one.
    size_t offset = 0;
    for (int i = 0; i < count; i++) {
        int slen = strlen(strs[i]);
        offset += sprintf(encoded + offset, "%d#%s", slen, strs[i]);
    }
    return encoded;
}

typedef struct {
    char **strs;
     int count;
} Decoderes;

Decoderes decode(const char *encoded) {
    Decoderes res;
    int capacity = 10;
    res.strs = malloc(capacity * sizeof(char *));
    res.count = 0;
    const char *p = encoded;
    while (*p != '\0'){
        int len = 0;
        while (*p != '#') {
            len = len * 10 + (*p - '0');
            p++;
        }
        p++;
        char *s = malloc(len + 1);
        memcpy(s, p, len);
        s[len] = '\0';
        p += len;
        if (res.count == capacity) {
            capacity *= 2;
            res.strs = realloc(res.strs, capacity * sizeof(char *));
        }
        res.strs[res.count++] = s;
    }
    return res;
}

int main(){
    //char *s[] = {"waba", "waba", "waba"};
    char *s[] = {
        "abcdefghijklm",
        "nopqrstuvwxyz",
        "mnopqrstuvw",
        "xyz",
        "mno",
        "wxy",
        "azbycxdwevfugthsirjqkplomn"
};
    int retsize;
    int size = sizeof(s) / sizeof(s[0]);
    char **res = encode_decode_strs(s, size, &retsize);
    printf("[");
    for (int i = 0; i < retsize; i++){
        printf("\"%s\", ", res[i]);
        free (res[i]);
    }
    printf("\b\b]\n");
    free (res);
}
