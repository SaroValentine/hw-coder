#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool isBrother(string s1, string s2)
{
    if (s1 == s2 || s1.size() != s2.size())
        return false;
    unordered_map<char, int> tmp;
    for (int i = 0; i < s1.size(); i++)
    {
        tmp[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        tmp[s2[i]]--;
    }
    for (auto it = tmp.begin(); it != tmp.end(); it++)
    {
        if (it->second != 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> strs(n);
        string word;
        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> strs[i];
        }
        cin >> word;
        cin >> k;

        vector<string> res;
        unordered_map<string, int> tmp;

        for (int i = 0; i < strs.size(); i++)
        {
            if (isBrother(strs[i], word))
            {
                if (tmp.find(strs[i]) != tmp.end())
                    continue;
                res.push_back(strs[i]);
            }
        }
        sort(res.begin(), res.end());

        cout << res.size() << endl;
        if (res.size() != 0)
            cout << res[k - 1] << endl;
    }
    return 0;
}