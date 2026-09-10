#include <limits.h>
#include <stdlib.h>
#include <threads.h>
char *MinWindowSubstring(char *s, char *t){
    int count1[128] = {0}, count2[128] = {0};
    int left = 0, bestret = INT_MAX, bestleft = 0;
    for (int i = 0; t[i]; i++)
        count1[(unsigned char)t[i]]++;
    for (int right = 0; s[right]; right++){
        count2[(unsigned char)s[right]]++;
        int same = 1;
        for (int i = 0; i < 128; i++){
            if (count2[i] < count1[i]){
                same = 0;
                break;
            }
        }
        while (same){
            if (right - left + 1 < bestret){
                bestret = right - left + 1;
                bestleft = left;
            }
            count2[(unsigned char)s[left]]--;
            left++, same = 1;
            for (int i = 0; i < 128; i++){
                if (count2[i] < count1[i]){
                    same = 0;
                    break;
                }
            }
        }
    }
    if (bestret == INT_MAX)
        return "";
    char *ret = malloc(bestret + 1);
    for (int i = 0; i < bestret; i++)
        ret[i] = s[bestleft + i];
    ret[bestret] = '\0';
    return ret;
}
#include <stdio.h>
int main(){
    char s[] = "ADOBECODEBANC", t[] = "ABC";
    printf("%s\n", MinWindowSubstring(s, t));
}
