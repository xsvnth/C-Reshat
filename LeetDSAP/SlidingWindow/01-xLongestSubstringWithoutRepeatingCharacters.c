int longestSub(char *s){
    int count[26] = {0};
    int left = 0, right = 0, max = 0;
    while (s[right]) {
        count[(unsigned char)s[right] - 'a']++;
        while (count[(unsigned char)s[right] - 'a'] > 1)
            count[(unsigned char)s[left] - 'a']--, left++;
        if (right - left + 1 > max)
            max = right - left + 1;
        right++;
    }
    return max;
}
#include <stdio.h>
int main(){
    char s[] = "abcabcbb";
    printf("%d\n", longestSub(s));
}
