#include <stdio.h>
#include <malloc.h>

/**
 * 存储结构体
 */
typedef struct {
    int *data;//数据指针，内存空间连续，如果要存放10个int，则每个int 4个字节，需要申请10*4个大小
    int size;//当前存储了多少元素
    int cap//最大容量，如果size到达了cap，则对date空间扩容
} LineTable;



/**
 * 初始化表
 * @param table
 */
void initLineTable(LineTable *table) {
    //对data进行内存空间分配，10 * sizeof(int)可以存放10个int
    table->data = (int *) malloc(10 * sizeof(int));
    //当前存放的数量
    table->size = 0;
    //当前最大容量
    table->cap = 10;
}


/**
 * 插入
 * @param table
 * @param value 插入的之
 * @param pos  插入的位置
 */
void insertValue(LineTable *table, int value, int pos) {
    /**
     * 如果插入的位置大于容量-1,或者小于0，则输入不对
     *
     * 因为下表从0开始，所以最大的下标就是容量-1，
     */
    if (pos > table->cap - 1 || pos < 0) {
        return;
    }
    /**
     * 如果当前存储的数量等于最大容量，则扩容
     */
    if (table->size == table->cap) {
        //在原有基础上扩容10*4个大小
        int *newData = realloc(table->data, 10 * sizeof(int));
        //原来的地址等于新的地址
        table->data = newData;
        //新的容量等于旧的容量+10
        table->cap = table->cap + 10;
    }

    /**
     *  因为是插入，倒叙遍历，当前节点等于前一个节点的值
     * 如 1 2 3 4,插入的位置如果是2,值是6 则最后的结果为1 2 6 3 4
     *
     * 倒叙遍历完成后其实结果是1 2 2 3 4，最后直接对pos的位置进行赋值即可。
     */
    for (int i = table->cap - 1; i > pos; --i) {
        table->data[i] = table->data[i - 1];
    }
    table->data[pos] = value;

    //元素数量+1
    table->size++;
}

/**
 * 删除元素
 * @param table
 * @param pos
 */
void deleteValue(LineTable *table, int pos) {
    /**
     * 正序遍历，当前的索引等于+1索引的值
     */
    for (int i = pos; i < table->cap; ++i) {
        table->data[i] = table->data[i + 1];
    }
    //元素数量-1
    table->size--;
}

/**
 * 打印
 * @param table
 */
void printTable(LineTable *table) {
    for (int i = 0; i < table->size; ++i) {
        printf("%d ", table->data[i]);
    }
    printf("\n");
}

void main() {
    LineTable lineData;
    initLineTable(&lineData);

    /**
     * 插入5个元素,结果为1 1 1 1 1
     */
    for (int i = 0; i < 5; ++i) {
        insertValue(&lineData,1,0);
    }
    printTable(&lineData);
    /**
     * 插入5个元素，结果为2 2 2 2 2 1 1 1 1 1
     */
    for (int i = 0; i < 5; ++i) {
        insertValue(&lineData,2,0);
    }
    printTable(&lineData);

    deleteValue(&lineData,1);

    printTable(&lineData);

}