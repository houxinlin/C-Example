#include <string.h>
#include <stdio.h>

void find(char s[], int count[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
            count[s[c] - 'a']++;
        }
        c++;
    }
}

void main() {
    /**
     * 思路是建立一个26位的int数组，逐个遍历字符串，取出单个字符，直接这个‘字符-a’得到他所在的数组位置，自增
     */
    char str[] = "abccsaa";
    int count[26] = {0};
    find(str, count);

    for (int i = 0; i < 26; ++i) {
        printf("%c \t  %d\n", i + 'a', count[i]);
    }

}