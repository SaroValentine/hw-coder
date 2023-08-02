#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    int res = 0;
    while (cin >> str1 >> str2)
    {
        for (int i = 0; i < str1.size(); i++)
        {
            for (int j = i; j < str1.size(); j++)
            {
                string tmp = str1.substr(i, j - i + 1);
                int pos = str2.find(tmp);
                if (pos != -1 && tmp.size() > res)
                {
                    res = tmp.size();
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}