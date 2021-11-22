#include <stdio.h>
#define printf(x, y) printf(x, 10);


int main()
{
    printf("%d", 1111);
    return 0;
}