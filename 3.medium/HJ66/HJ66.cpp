#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<pair<string, string>> instr = {
    {"reset", ""},
    {"reset", "board"},
    {"board", "add"},
    {"board", "delete"},
    {"reboot", "backplane"},
    {"backplane", "abort"},
};
vector<string> opr = {
    "reset what",
    "board fault",
    "where to add",
    "no board at all",
    "impossible",
    "install first",
    "unknown command",
};

int main()
{
    string input;
    while (getline(cin, input))
    {
        // 分词
        string str1, str2;
        int pos = 0;
        for (int i = 0; i < input.size(); i++)
            if (input[i] == ' ')
                pos = i;
        if (pos == 0)
            str1.assign(input, 0, input.size());
        else
        {
            str1.assign(input, 0, pos);
            str2.assign(input, pos + 1, input.size());
        }
        // 处理词的匹配, 使用string的find
        // 逐个遍历命令集合
        int cnt1 = 0, cnt2 = 0; // 关键字匹配次数
        string output;
        for (auto it = instr.begin(); it != instr.end(); it++)
        {
            int find1 = 0, find2 = 0;
            // 找到str1的情况
            if ((*it).first.find(str1) == 0)
                find1++;
            // 找到str2的情况
            if ((*it).second.find(str2) == 0 && str2 != "")
                find2++;
            // 找到str1并且只有一个关键字的情况
            if (find1 == 1 && str2 == "" && (*it).second == "")
                cnt1++;
            // 找到str1和str2的情况
            if (find1 == 1 && find2 == 1)
            {
                cnt1++;
                cnt2++;
                output = opr[it - instr.begin()];
            }
        }
        if (cnt1 == 1 && cnt2 == 1)
            cout << output << endl;
        else if (cnt1 != 0 && cnt2 == 0)
            cout << opr[0] << endl;
        else
            cout << opr[6] << endl;
    }
    return 0;
}