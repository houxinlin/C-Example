
#include <stdio.h>


int getNum(char ch)
{
    int num = 0;
    if (ch >= '0' && ch <= '9') {
        num = ch - 0x30;
    }
    else {
        switch (ch) {
            case 'A':
            case 'a':
                num = 10;
                break;
            case 'B':
            case 'b':
                num = 11;
                break;
            case 'C':
            case 'c':
                num = 12;
                break;
            case 'D':
            case 'd':
                num = 13;
                break;
            case 'E':
            case 'e':
                num = 14;
                break;
            case 'F':
            case 'f':
                num = 15;
                break;
            default:
                num = 0;
        }
    }
    return num;
}


unsigned int hex2int(unsigned char hex[])
{
    unsigned int x = 0;
    x = (getNum(hex[0])) * 16 + (getNum(hex[1]));
}

int main()
{
    unsigned char hexValue[2] = "95A";
    unsigned int intValue = 0;

    intValue = hex2int(hexValue);

    printf("value is: %d\n", intValue);

    return 0;
}