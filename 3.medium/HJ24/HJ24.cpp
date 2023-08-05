#include <iostream>
#include <vector>
using namespace std;

// 通过最长递增序列和最长递减序列的逻辑
int solution(vector<int> height)
{
    int len = height.size();
    vector<int> dpUp(len, 1);
    vector<int> dpDown(len, 1);

    // 递增子序列
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (height[i] > height[j])
            {
                dpUp[i] = max(dpUp[i], dpUp[j] + 1);
            }
        }
    }

    // 递减子序列
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = len - 1; j > i; j--)
        {
            if (height[i] > height[j])
            {
                dpDown[i] = max(dpDown[i], dpDown[j] + 1);
            }
        }
    }
    int res = 0;
    // 遍历每个位置对应的最长递增子序列和递减子序列
    for (int i = 0; i < len; i++)
    {
        if (dpDown[i] + dpUp[i] - 1 > res)
            res = dpDown[i] + dpUp[i] - 1;
    }
    return len - res;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> height(n);
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }
        cout << solution(height);
    }
    return 0;
}