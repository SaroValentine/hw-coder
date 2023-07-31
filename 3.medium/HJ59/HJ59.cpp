#include <iostream>
using namespace std;

int main()
{
    int a[128] = {0};
    string str;
    char c;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        a[str[i]]++;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (a[str[i]] == 1)
        {
            c = str[i];
            break;
        }
    }
    if (c != NULL)
    {
        cout << c;
    }
    else
    {
        cout << -1;
    }
}
