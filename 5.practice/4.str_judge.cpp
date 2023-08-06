/*
** https://www.nowcoder.com/questionTerminal/5382ff24fbf34a858b15f93e2bd85307
*/
// 双指针
#include <iostream>
using namespace std;

int main()
{
    string s;
    string t;
    getline(cin, s);
    getline(cin, t);
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if (i == s.size())
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    return 0;
}