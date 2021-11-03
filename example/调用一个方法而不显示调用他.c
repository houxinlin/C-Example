#include <stdio.h>

int puts(const char *str) {
    fputs("Hello, world!\n", stdout);
}

int main() {
    printf("Goodbye!\n");
}