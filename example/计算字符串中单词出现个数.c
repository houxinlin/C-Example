#include <stdio.h>
#include <string.h>
#define maxsize 100
int countOccurrences(char * str, char * toSearch);

int main()
{
    char str[maxsize];
    char toSearch[maxsize];
    int count;

    printf("输入一串字符");
    gets(str);
    printf("输入要统计的单词");
    gets(toSearch);

    count = countOccurrences(str, toSearch);

    printf("单词'%s': %d", toSearch, count);

    return 0;
}


int countOccurrences(char * str, char * toSearch)
{
    int x, j, found, count;
    int stringLen, searchLen;

    stringLen = strlen(str);      
    searchLen = strlen(toSearch);

    count = 0;

    for(x=0; x <= stringLen-searchLen; x++)
    {

        found = 1;
        for(j=0; j<searchLen; j++)
        {
            if(str[x + j] != toSearch[j])
            {
                found = 0;
                break;
            }
        }

        if(found == 1)
        {
            count++;
        }
    }

    return count;
}
