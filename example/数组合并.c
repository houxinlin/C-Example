#include <stdio.h>
void mergeSorted(int src1[], int src2[],
                 int newArr[], int n1, int n2, int n3)
{
    for (int i = 0; i < n1; ++i)
    {
        newArr[i] = src1[i];
    }

    for (int i = 0, j=n1; j < n3; ++i, ++j)
    {
        newArr[j] = src2[i];
    }
}

int main()
{
    int src1[] = {10, 20, 30, 40, 50};
    int src2[] = {9, 18, 27, 36, 45};

    int n1 = sizeof(src1)/sizeof(src1[0]);
    int n2 = sizeof(src2)/sizeof(src2[0]);

    int n3 = n1 + n2;

    int newArr[n3];

    mergeSorted(src1, src2, newArr, n1, n2, n3);

    for (int i = 0; i < n3; i++) {
        printf("%d ",newArr[i]);
    }

    return 0;
}