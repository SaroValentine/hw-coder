#include <string>
#include <iostream>
#include <vector>

using namespace std;

int match_string(string str, string pattern)
{
    int len1 = str.size();
    int len2 = pattern.size();
    vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1, 0));
    // 多加一行一列作为初始初值所用
    dp[0][0] = 1; // 初始化
    for (int i = 1; i <= len2; i++)
    {
        char ch1 = pattern[i - 1];
        ////设置每次循环的初值，即当星号不出现在首位时，匹配字符串的初值都为false
        dp[i][0] = dp[i - 1][0] && (ch1 == '*');
        for (int j = 1; j <= len1; j++)
        {
            char ch2 = str[j - 1];
            if (ch1 == '*')
            {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // 当匹配字符为*号时，可以匹配0个或者多个
            }
            else
            {
                if (isalpha(ch2))
                { // ch2为字母时，尝试是否能匹配
                    dp[i][j] = dp[i - 1][j - 1] && (ch1 == '?' || (ch2 == ch1 || ch2 == (ch1 + ('A' - 'a')) || ch2 == (ch1 - ('A' - 'a'))));
                }
                else if (isdigit(ch2))
                { // ch2为数字时，尝试是否能匹配
                    dp[i][j] = dp[i - 1][j - 1] && (ch1 == '?' || (ch1 == ch2));
                }
                else
                { // ch2既不为字母也不为数字时，只有ch1和ch2相同才能匹配
                    dp[i][j] = dp[i - 1][j - 1] && (ch1 == ch2);
                }
            }
        }
    }
    return dp[len2][len1];
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int flag = match_string(str2, str1);
        if (flag)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
}
