#include <stdio.h>

void main() {
    /**
     * 思路是三层循环，
     * 第一层试图是0到数组大小
     * 第二层是上一层+1到数组大小
     *
     * 在第二层中做判断，如果第二层的数据和第一层数据相等，则意味着发现重复数据，那么开启第三层for
     *
     * 第三层中做的事情就是从第二层的位置开始，元素向前移动，
     *
     * 此时数组就应该-1,因为被废弃了一个重复元素
     */
    int data[4] = {1, 2, 2,4};
    int size = sizeof data / sizeof data[0];
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (data[j] == data[i]) {
                for (int k = j; k < size; ++k) {
                    data[k] = data[k + 1];
                }
                size--;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
}