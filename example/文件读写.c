#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

struct Student {
    int roll;
    char name[12];
    int percent;
} s1 = {96, "VINEET", 76};

void main() {
    int file = fopen("/home/a/file.txt", "r");

    char data[] = "数据\n\n数据";
    //写入数据
    fwrite(data, strlen(data), 1, file);
    char buf[255];

    int nread;
    //读出数据
    while ((nread = fread(buf, 1, sizeof buf, file)) > 0)
        printf("%s",buf);

    fclose(file);
};

