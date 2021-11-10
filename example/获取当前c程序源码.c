#include<stdio.h>

int main(){
    FILE  *file;
    char ch;
    file= fopen(__FILE__,"r");
    do {
        ch = getc(file);
        putchar(ch);
    } while (ch!=EOF);
    fclose(file);
    return 0;
}