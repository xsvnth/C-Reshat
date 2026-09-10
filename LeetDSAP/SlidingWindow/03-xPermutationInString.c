int checkInclusion(char *s1, char *s2){
    int left = 0, len = 0, count1[26] = {0}, count2[26] = {0};
    while (s1[left])
        count1[(unsigned char)s1[left] - 'a']++, left++, len++;
    for (int right = 0; s2[right]; right++){
        count2[(unsigned char)s2[right] - 'a']++;
        if (right >= len)
            count2[(unsigned char)s2[right - len] - 'a']--;
        if (right >= len - 1){
            int same = 1;
            for (int i = 0; i < 26; i++){
                if (count1[i] != count2[i]){
                    same = 0;
                    break;
                }
            }
            if (same)
                return 1;
        }
    }
    return 0;
}
#include <stdio.h>
int main(){
    char s1[] = "ab", s2[] = "eidbaooo";
    printf("%d\n", checkInclusion(s1, s2));
}
