#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> weight(n);
        vector<int> num(n);
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> num[i];

        // 将所有砝码放在一个容器内
        vector<int> total;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < num[i]; j++)
            {
                total.push_back(weight[i]);
            }
        }
        // 用set去重，存放所有可能的结果
        set<int> res;
        res.insert(0);
        for (int i = 0; i < total.size(); i++)
        {
            // 临时set，存放当前砝码加入后的所有可能结果
            set<int> tmp;
            for (auto it = res.begin(); it != res.end(); it++)
            {
                tmp.insert(*it + total[i]);
            }
            for (auto it = tmp.begin(); it != tmp.end(); it++)
            {
                res.insert(*it);
            }
        }
        printf("%lu", res.size());
    }
    return 0;
}
