#include<stdio.h>
int main() {
    //判断回文的原理是，数字反转，因为回文反转后还是原来本身
    //比如121,数组反转的原理分为3步骤。
    //1 求出这个数的个位数
    //2 累加，累加时要先扩大10倍，把个位数预留出来，然后加上上一步的结果，
    //3 原数/10,意味着个位数已经被计算过了。改丢弃了


    //下面这个遍历2此，用来演示
    {
        int i = 12;
        int temp = i;
        int sum = 0;
        {
            int p = temp % 10;//1
            sum = sum * 10 + p;//2
            temp = temp / 10;//3
        }
        {
            int p = temp % 10;//1
            sum = sum * 10 + p;//2
            temp = temp / 10;//3
        }
//        printf("%d", sum);
    }
    //通过while遍历
    {
        int i = 12321;
        int temp = i;
        int sum = 0;
        while (temp != 0) {
            int p = temp % 10;//1
            sum = sum * 10 + p;//2
            temp = temp / 10;//3
        }
        printf("%d是否回文 %s", i, i == sum ? "是" : "不是");

    }
    return 0;
}
