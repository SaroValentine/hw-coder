#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calcute(vector<int> a, vector<int> b, int &sum)
{
    sum += a[0] * a[1] * b[1];
    return vector<int>{a[0], b[1]};
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<vector<int>> arr;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            arr.push_back(vector<int>{a, b});
        }
        string s;
        cin >> s;
        int sum = 0;
        stack<vector<int>> sta;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                continue;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                sta.push(arr[s[i] - 'A']);
            }
            else if (s[i] == ')')
            {
                vector<int> tmp1 = sta.top();
                sta.pop();
                vector<int> tmp2 = sta.top();
                sta.pop();
                sta.push(calcute(tmp2, tmp1, sum));
            }
            else
            {
                continue;
            }
        }
        cout << sum;
    }
}
