#include<stdio.h>

int main() {
    int i, j, x, temp, array[50];
    printf("输入元素个数: ");
    scanf("%d", &x);
    printf("输入元素值: ", x);
    for (i = 0; i < x; i++) {
        scanf("%d", &array[i]);
    }
    for (i = 1; i < x; i++) {
        //把当前遍历的元素临时存储，  这个值可能是最小的，那么会把他一直向前移动
        temp = array[i];
        //当前遍历的元素的上一个元素开始位置，j会一直-1,用来向前移动
        j = i - 1;
        //条件是当前遍历的元素值一直小于j索引处的值，并且j控制在0以上
        while ((temp < array[j]) && (j >= 0)) {
            //如果小于，那么后一个元素=前一个元素，即元素开始向前移动，
            // 但是内存中会出现两个相同之值，比如[4,5,1]
            //当1向前移动，意味着5要覆盖1的位置，最终结果是[4,5,5]，所以写法是array[j + 1] = array[j]，因为一开始j比遍历的索引小1。然后以此推
            //下一次遍历的结果就是[4,4,5]
            //但是此时的temp中存储的是一开始要遍历的元素，最后在结束的时候，会把这个值放在最前面
            array[j + 1] = array[j];
            j = j - 1;
        }
        //把最小的值放在最前面，如果当前遍历的元素不大于上一个元素
        array[j + 1] = temp;
    }

    for (i = 0; i < x; i++) {
        printf("%d", array[i]);
    }

    return 0;
}
