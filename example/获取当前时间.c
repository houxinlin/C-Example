#include <stdio.h>
#include <time.h>

int main()
{
    time_t tm;
    char* curDateTime;
    time(&tm);

    curDateTime = ctime(&tm);
    printf("当前时间 %s", curDateTime);

    return (0);
}