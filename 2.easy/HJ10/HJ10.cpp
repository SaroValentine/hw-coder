#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    while (cin >> str)
    {
        vector<int> arr(128);
        for (int i = 0; i < str.size(); i++)
        {
            arr[str[i]]++;
        }
        int count = 0;
        for (int i = 0; i < 128; i++)
        {
            if (arr[i] != 0)
            {
                count++;
            }
        }
        printf("%d", count);
    }
    return 0;
}
