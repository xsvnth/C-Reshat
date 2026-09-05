#include <stdbool.h>
#include <string.h>
bool isPalindrome(char *s){
    int size = strlen(s);
    if (!size)
        return true;
    for (int i = 0; i < size; i++){
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    char *p1 = s, *p2 = s + size - 1;
    while (p1 < p2){
        while (p1 < p2 && !((*p1 >= 'a' && *p1 <= 'z') 
                    || (*p1 >= '0' && *p1 <= '9')))
            p1++;
        while (p2 > p1 && !((*p2 >= 'a' && *p2 <= 'z')
                    || (*p2 >= '0' && *p2 <= '9')))
            p2--;
        if (p1 > p2)
            break;
        if (*p1 != *p2)
            return false;
        p1++, p2--;
    }
    return true;
}
#include <stdio.h>
int main(){
    char s[] = "A man, a plan, a canal: Panama";
    printf("%d\n", isPalindrome(s));
}
