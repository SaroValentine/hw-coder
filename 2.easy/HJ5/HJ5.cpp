#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;
int converse(char c)
{
    if (c == 'A' || c == 'a')
        return 10;
    else if (c == 'B' || c == 'b')
        return 11;
    else if (c == 'C' || c == 'c')
        return 12;
    else if (c == 'D' || c == 'd')
        return 13;
    else if (c == 'E' || c == 'e')
        return 14;
    else if (c == 'F' || c == 'f')
        return 15;
    return c - '0';
}

int main()
{
    string str;
    while (cin >> str)
    {
        int sum = 0;
        for (int i = str.size() - 1; i > 1; i--)
        {
            int tmp = converse(str[i]);
            sum += tmp * pow(16, str.size() - 1 - i);
        }
        printf("%d", sum);
    }
    return 0;
}