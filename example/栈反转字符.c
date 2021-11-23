
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];

int pos = -1;

void push(char ch) {
    stack[++pos] = ch;
}

char pop() {
    char result = stack[pos];
    pos--;
    return result;
}

int main() {
    char str[MAX];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); ++i) {
        push(str[i]);
    }

    for (int i = 0; i < strlen(str); ++i) {
        str[i] = pop();
    }
    printf("%s", str);

}