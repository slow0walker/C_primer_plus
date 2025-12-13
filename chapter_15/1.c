#include <stdio.h>
#include <string.h>

// 主要原理：利用秦九韶算法和位运算实现二进制字符串转十进制整数
/*
int bintodec(const char *binstr)
{
    int res = 0;
    for (int i = 0; binstr[i] != '\0'; i++)
    {
        res = res * 2 + (binstr[i] - '0');
    }
    return res;
}
*/

/* int bintodec(const char *binstr)
{
    int res=0;
    for(int i=0;binstr[i]!='\0';i++)
    {
        res =(res<<1)|(binstr[i]-'0');
    }
    return res;
}
*/

/* int bintodec(const char *binstr)
{
    int res = 0;
    for (int i = 0; binstr[i] != '\0'; i++)
    {
        res += (binstr[i] - '0') << (strlen(binstr) - 1 - i);
    }
    return res;
} */

/* int bintodec(const char *binstr)
{
    int res = 0;
    for (int i = 0; binstr[i] != '\0'; i++)
    {
        if (binstr[i] == '1')
        {
            res += 1 << (strlen(binstr) - 1 - i);
        }
    }
    return res;
}
 */

/*  int bintodec(const char *binstr)
 {
    int res = 0;
    for (int i = 0; binstr[i] != '\0'; i++)
    {
        if (binstr[i] == '1')
        {
            res |= 1 << (strlen(binstr) - 1 - i);
        }
    }
    return res;
 } */
int bintodec(const char *binstr)
{
    int res = 0;
    while (*binstr)
    {
        res = (res << 1) | (*binstr++ - '0');
    }
    return res;
}

int main()
{
    char binstr[65];
    printf("Enter a binary number: ");
    scanf("%s", binstr);
    int decimal = bintodec(binstr);
    printf("The decimal equivalent is: %d\n", decimal);
    return 0;
}