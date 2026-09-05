#include <stdbool.h>
#include <string.h>
bool isAnagram(char* s, char* t) {
    int a[256] = {0};
    if (strlen(s) != strlen(t))
        return false;
    while (*s)
        a[(unsigned char)*s++]++, a[(unsigned char)*t++]--;
    for (int i = 0; i < 256; i++)
            if (a[i])
                return false;
    return true;
}
#include <stdio.h>
int main(){
    char a[] = "silent", b[] = "listen";
    printf("%d\n", isAnagram(a, b));
}
