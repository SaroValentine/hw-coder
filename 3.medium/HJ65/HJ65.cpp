#include <iostream>
using namespace std;

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        string tmp;
        if (a.size() > b.size())
        {
            tmp = a;
            a = b;
            b = tmp;
        }
        string res;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = i; j < a.size(); j++)
            {
                tmp = a.substr(i, j - i + 1);
                if (b.find(tmp) != string::npos && tmp.size() > res.size())
                {
                    res = tmp;
                }
            }
        }
        cout << res;
    }
}
