#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, m;
    cin >> N >> m;

    // 处理特殊情况，当预算N或物品数量m为0时，直接输出0并结束程序
    if (0 == N || 0 == m) {
        cout << 0 << '\n';
        return 0;
    }

    N /= 10; // 将预算除以10，因为物品价格都是10的倍数，方便后续计算

    // 初始化weights和values二维数组，表示每个物品及其附件的重量和价值
    vector<vector<int>> weights(m + 1, vector<int>(3, 0));
    vector<vector<int>> values(m + 1, vector<int>(3, 0));

    int v = 0, p = 0, q = 0; // v表示物品的重量，p表示物品的价值，q表示附件所属主件的编号

    // 读取每个物品及其附件的重量和价值
    for (int i = 1; i <= m; ++i) {
        cin >> v >> p >> q;
        v /= 10; // 将物品重量除以10，方便后续计算

        if (0 == q) {
            // 若q为0，表示当前物品没有附件
            weights[i][0] = v;
            values[i][0] = v * p;
        } else {
            // 若q不为0，表示当前物品是某个主件的附件
            if (0 == weights[q][1]) {
                weights[q][1] = v;
                values[q][1] = v * p;
            } else {
                weights[q][2] = v;
                values[q][2] = v * p;
            }
        }
    }

    // 初始化dp二维数组，表示前i个物品中花费不超过j的情况下能够达到的最大价值
    vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));

    int w0 = 0, w1 = 0, w2 = 0, w3 = 0, v0 = 0, v1 = 0, v2 = 0, v3 = 0;

    // 动态规划求解
    for (int i = 1; i <= m; ++i) {
        w0 = weights[i][0], v0 = values[i][0];
        w1 = w0 + weights[i][1], v1 = v0 + values[i][1];
        w2 = w0 + weights[i][2], v2 = v0 + values[i][2];
        w3 = w1 + w2 - w0, v3 = v1 + v2 - v0;

        for (int j = 0; j <= N; ++j) {
            dp[i][j] = (j >= w0) ? max(dp[i - 1][j], dp[i - 1][j - w0] + v0) : dp[i - 1][j];
            dp[i][j] = (j >= w1) ? max(dp[i][j], dp[i - 1][j - w1] + v1) : dp[i][j];
            dp[i][j] = (j >= w2) ? max(dp[i][j], dp[i - 1][j - w2] + v2) : dp[i][j];
            dp[i][j] = (j >= w3) ? max(dp[i][j], dp[i - 1][j - w3] + v3) : dp[i][j];
        }
    }

    cout << dp.back().back() * 10 << endl;
    return 0;
}
