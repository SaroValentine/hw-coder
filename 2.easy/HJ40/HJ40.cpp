#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int chact = 0, backspace = 0, num = 0, oth = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
            chact++;
        else if (str[i] == ' ')
            backspace++;
        else if (str[i] >= '0' && str[i] <= '9')
            num++;
        else
            oth++;
    }
    printf("%d\n%d\n%d\n%d", chact, backspace, num, oth);
    return 0;
}
