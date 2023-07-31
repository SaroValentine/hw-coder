#include <iostream>
#include <string>
#include <map>
using namespace std;
bool IsAllCharExist(string str1, string str2)
{
    int len1 = str1.size(), len2 = str2.size();
    map<char, int> map;
    for (int i = 0; i < len2; ++i)
        map[str2[i]] = 1;
    for (int i = 0; i < len1; ++i)
        if (map[str1[i]] != 1)
            return false;
    return true;
}
int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        if (IsAllCharExist(str1, str2))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}