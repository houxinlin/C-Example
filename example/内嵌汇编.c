#include <stdlib.h>
int a = 10;
int b = 3;

void main() {
    asm(
    "mov a,%eax\n\t"
    "mov %eax,b"
    );
    printf("%d",b);
}