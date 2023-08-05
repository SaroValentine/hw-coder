#include <iostream>
#include <string.h>
using namespace std;

// 判断是否有效字符串
bool isValid(string s)
{
    if (s.size() == 0)
        return false;
    if (s[0] != 'A' && s[0] != 'D' && s[0] != 'W' && s[0] != 'S')
        return false;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

// 移动字符串
void move(string s, int &x, int &y)
{
    // 将字符串s用";" 分割
    char *p = strtok((char *)s.c_str(), ";");
    while (p)
    {
        string temp = p;
        if (!isValid(temp))
        {
            p = strtok(NULL, ";");
            continue;
        }
        int num = 0;
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] >= '0' && temp[i] <= '9')
                num = num * 10 + temp[i] - '0';
        }
        switch (temp[0])
        {
        case 'A':
            x -= num;
            break;
        case 'D':
            x += num;
            break;
        case 'W':
            y += num;
            break;
        case 'S':
            y -= num;
            break;
        }
        p = strtok(NULL, ";");
    }
}

int main()
{
    string str;
    while (cin >> str)
    {
        // 定义初始坐标
        int x = 0;
        int y = 0;
        move(str, x, y);
        cout << x << "," << y << endl;
    }
    return 0;
}
