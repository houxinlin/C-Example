
#include <stdio.h>



int substring(char* source, int from, int n, char* target)
{
    int length, i;
    for (length = 0; source[length] != '\0'; length++)
        ;

    if (from > length) {
        return 1;
    }

    if ((from + n) > length) {
        n = (length - from);
    }

    for (i = 0; i < n; i++) {
        target[i] = source[from + i];
    }
    target[i] = '\0';

    return 0;
}

int main()
{
    char str[100], targetString[100];
    int from, n;

    printf("输入字符");
    gets(str);

    printf("从第几个位置开始截取？");
    scanf("%d", &from);

    printf("截取长度?: ");
    scanf("%d", &n);

    if (substring(str, from, n, targetString) == 0) {
        printf("子字符串 is: %s\n", targetString);
    }

    return 0;
}