
#include <malloc.h>
#include <stdlib.h>

typedef struct LinkTableNode {
    int data;
    struct LinkTableNode *next;
} LinkTable;

LinkTable *createNode(int value) {
    LinkTable *node = (LinkTable *) malloc(sizeof(LinkTable));
    node->data = value;
    node->next = NULL;
    return node;
}

void addTail(LinkTable *table, int value) {
    LinkTable *temp = table;
    while (temp != NULL) {
        if (temp->next == NULL) {
            LinkTable *node = createNode(value);
            node->data = value;
            temp->next = node;
            return;
        }
        temp = temp->next;
    }
}

LinkTable *addHeader(LinkTable *table, int value) {
    LinkTable *node = createNode(value);
    node->next = table;
    return node;
}

int readIntValue() {
    int i;
    scanf("%d", &i);

    return i;
}

LinkTable *initTable(int size) {
    LinkTable *node = NULL;
    printf("插入%d个数字\n", size);
    for (int i = 0; i < size; ++i) {
        LinkTable *newNode = createNode(readIntValue());
        newNode->next = node;
        node = newNode;
    }
    return node;
}

LinkTable *deleteByIndex(LinkTable *table, int index) {
    LinkTable *temp = table;
    if (index == 0) { return table->next->next; }
    for (int i = 1; i < index; ++i) {
        temp = temp->next;
        if (temp == NULL) { return table; }
    }
    temp->next = temp->next->next;
    return table;
}

int indexOf(LinkTable *table, int value) {
    LinkTable *temp = table;
    int index = -1;
    for (;;) {
        index++;
        if (value == temp->data) { return index; }
        temp = temp->next;
        if (temp == NULL) { return -1; }
    }
}

void *insert(LinkTable *linkTable, int value, int pos) {
    LinkTable *newNode = malloc(sizeof(LinkTable));
    newNode->data = value;
    LinkTable *temp = linkTable;
    for (int i = 1; i < pos; i++) {
        if (temp->next != NULL) {
            temp = temp->next;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void printTable(LinkTable *table) {
    while (table != NULL) {
        printf("%d ", table->data);
        table = table->next;
    }
    printf("\n");
}

void main() {
    LinkTable *header = initTable(5);
    printTable(header);
    printf("元素3的位置在%d\n", indexOf(header, 3));

    header = deleteByIndex(header, indexOf(header, 3));
    printTable(header);

    header = addHeader(header, 22);
    printTable(header);

    addTail(header, 55);
    printTable(header);
}