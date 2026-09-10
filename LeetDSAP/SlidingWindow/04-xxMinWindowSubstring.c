#include <stdlib.h>
#include <limits.h>
char *MinWindowSubstring(char* s, char* t) {
    int count1[128] = {0}, count2[128] = {0};
    int required = 0, formed = 0, left = 0;
    int bestRet = INT_MAX, bestLeft = 0;
    for (int i = 0; t[i]; i++) {
        if (count1[(unsigned char)t[i]] == 0)
            required++;
        count1[(unsigned char)t[i]]++;
    }
    for (int right = 0; s[right]; right++) {
        count2[(unsigned char)s[right]]++;
        if (count2[(unsigned char)s[right]] == count1[(unsigned char)s[right]])
            formed++;
        while (formed == required) {
            if (right - left + 1 < bestRet) {
                bestRet = right - left + 1;
                bestLeft = left;
            }
            count2[(unsigned char)s[left]]--;
            if (count2[(unsigned char)s[left]] < count1[(unsigned char)s[left]])
                formed--;
            left++;
        }
    }
    if (bestRet == INT_MAX)
        return "";
    char *ret = malloc(bestRet + 1);
    for (int i = 0; i < bestRet; i++)
        ret[i] = s[bestLeft + i];
    ret[bestRet] = '\0';
    return ret;
}
#include <stdio.h>
int main(){
    char s[] = "ADOBECODEBANC", t[] = "ABC";
    printf("%s\n", MinWindowSubstring(s, t));
}
