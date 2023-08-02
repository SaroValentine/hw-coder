#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;

bool dfs(vector<vector<int>>& nums, int m, int n, int i, int j) {
    if (i == m - 1 && j == n - 1) return true;
    if (i < 0 || i >= m || j < 0 || j >= n || nums[i][j] == 1 || nums[i][j] == -1) return false;
    nums[i][j] = -1;  // 标记已经走过了
    res.push_back({i, j});
    if (dfs(nums, m, n, i+1, j) || dfs(nums, m, n, i-1, j) || dfs(nums, m, n, i, j+1) || dfs(nums, m, n, i, j-1)) return true;
    nums[i][j] = 0;
    res.pop_back();
    return false;
}                   

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> nums(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) 
            cin >> nums[i][j];
            
    dfs(nums, m, n, 0, 0);
    for (auto& x : res) printf("(%d,%d)\n", x[0], x[1]);
    printf("(%d,%d)\n", m-1, n-1);
}