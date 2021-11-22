#include <stdio.h>
#include <malloc.h>

/**
 * 存储结构体
 */
typedef struct {
    int *data;//数据指针，内存空间连续，如果要存放10个int，则每个int 4个字节，需要申请10*4个大小
    int size;//当前存储了多少元素
    int capacity//最大容量，如果size到达了capacity，则对date空间扩容
} LineTable;


/**
 * 初始化表
 * @param table
 */
void initLineTable(LineTable *table) {
    //对data进行内存空间分配，10 * sizeof(int)可以存放10个int，当存放第11个时候需要扩容
    table->data = (int *) malloc(10 * sizeof(int));
    //当前存放的数量
    table->size = 0;
    //当前最大容量
    table->capacity = 10;
}


/**
 * 插入
 * @param table
 * @param value 插入的值
 * @param pos  插入的位置
 */
void insertValue(LineTable *table, int value, int pos) {
    /**
     *
     * 判断当前插入位置是否合法
     */
    if (pos > table->size || pos < 0) {
        return;
    }
    /**
     * 如果当前存储的数量等于最大容量，则扩容
     */
    if (table->size == table->capacity) {
        //新的容量等于旧的容量+10
        table->capacity = table->capacity + 10;

        //在原有基础上扩容10*4个大小
        int *newData = realloc(table->data, table->capacity * sizeof(int));
        //原来的地址等于新的地址
        table->data = newData;
    }

    /**
     *  因为是插入，倒叙遍历，当前节点等于前一个节点的值
     * 如 1 2 3 4,插入的位置如果是2,值是6 则最后的结果为1 2 6 3 4
     *
     * 倒叙遍历完成后其实结果是1 2 2 3 4，最后直接对pos的位置进行赋值即可。
     */
    for (int i = table->capacity - 1; i > pos; --i) {
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
    for (int i = pos; i < table->capacity-1; ++i) {
        table->data[i] = table->data[i + 1];
    }
    //元素数量-1
    table->size--;
}

int findFirstIndex(LineTable *table, int value) {
    for (int i = 0; i < table->size; ++i) {
        if (table->data[i] == value) {
            return i;
        }
    }
    return -1;
}

int findLastIndex(LineTable *table, int value) {
    for (int i = table->size - 1; i >= 0; --i) {
        if (table->data[i] == value) {
            return i;
        }
    }
    return -1;
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
        insertValue(&lineData, i, 0);
    }

    printf("初始化前:\n");
    printTable(&lineData);

    printf("删除索引3后:\n");
    deleteValue(&lineData,3);
    printTable(&lineData);

    printf("在索引2的位置插入9后\n");
    insertValue(&lineData,9,2);


    printTable(&lineData);

    int *i =(int *) malloc(6120000000);

    if(i==NULL){
        printf("a");
    }

}
