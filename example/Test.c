#include <stdio.h>
#include <malloc.h>

typedef struct {
    int value;
} HT;
void main(){
    HT *ht;
    ht=malloc(10);
    ht->value=10;
    printf("%d",ht->value);
}