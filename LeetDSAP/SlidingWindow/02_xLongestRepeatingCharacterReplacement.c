int LongestRepeating(char *s, int k){
    int left = 0, longest = 0, count[26] = {0}, max = 0;
    for (int right = 0; s[right]; right++){
        count[(unsigned char)s[right] - 'A']++;
        if (count[(unsigned char)s[right] - 'A'] > max)
            max = count[(unsigned char)s[right] - 'A'];
        while (right - left + 1 - max > k)
            count[(unsigned char)s[left] - 'A']--, left++;
        if (right - left + 1 > longest)
            longest = right - left + 1;
    }
    return longest;
}
#include <stdio.h>
int main(){
    char s[] = "AAABABB";
    int k = 1;
    printf("%d\n", LongestRepeating(s, k));
}
