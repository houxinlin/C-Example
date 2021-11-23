/*C program to convert String into Hexadecimal.*/

#include <stdio.h>
#include <string.h>

int main()
{
    unsigned char str[100]="三阿三的";
    char strH[200];
    int i, j;
    memset(strH, 0, sizeof(strH));

    for (i = 0, j = 0; i < strlen(str); i++, j += 2) {
        sprintf((char*)strH + j, "%02X", str[i]);
    }
    strH[j] = '\0';

    printf("%s\n", strH);

    return 0;
}