#include <stdbool.h>
bool isAnagram(char* s, char* t) {
    int a[256] = {0};
    while (*s)
        a[*s++]++, a[*t++]--;
    for (int i = 0; i < 256; i++)
            if (a[i])
                return false;
    return true;
}
#include <stdio.h>
int main(){
    char a[] = "silent", b[] = "sisten";
    printf("%d\n", isAnagram(a, b));
}
