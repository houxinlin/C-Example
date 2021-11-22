#include <stdio.h>
#include <time.h>

int main()
{
    time_t T = time(NULL);
    struct tm date = *localtime(&T);

    /**
     * tm_mon: 自 1 月以来的月数，范围为 0 到 11。
     * tm_year:自 1900 年以来的年数，注意是数量  不是年 。所以要加1900,才等于今年
     */
    printf("System Date is: %02d/%02d/%04d\n", date.tm_mon+1, date.tm_mday + 1, date.tm_year + 1900);
    printf("System Time is: %02d:%02d:%02d\n", date.tm_hour, date.tm_min, date.tm_sec);

    return 0;
}