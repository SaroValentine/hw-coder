#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 替换括号
void replace(string &s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{')
        {
            s[i] = '(';
        }
        if (s[i] == ']' || s[i] == '}')
        {
            s[i] = ')';
        }
    }
}
// 判断是否为运算符
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// 获取运算符的优先级
int getPriority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
// 计算两数的运算结果
int calculate(int num1, int num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            return -9999;
        }
        return num1 / num2;
    default:
        return -999999;
    }
}

// 计算表达式的值
int calculate(string s)
{
    stack<int> stknum;
    stack<char> stkope;

    for (int i = 0; i < s.size(); i++)
    {
        // 操作数入栈，包括正数和负数
        if (isdigit(s[i]) || (s[i] == '-' && (i == 0 || (i > 0 && !isdigit(s[i - 1]) && s[i - 1] != ')'))))
        {
            // 1.首位是负号
            // 2.不是首位，前一位也不是数字和右括号
            int sum = 0;
            int sign = 1;
            if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            while (i < s.size() && isdigit(s[i]))
            {
                sum = sum * 10 + (s[i] - '0');
                i++;
            }
            stknum.push(sum * sign);
            i--;
        }
        else if (s[i] == '(')
        { // 左括号入栈
            stkope.push(s[i]);
        }
        else if (s[i] == ')')
        { // 右括号计算
            while (!stkope.empty() && stkope.top() != '(')
            { // 弹出左括号前的所有运算符进行计算
                int num1 = stknum.top();
                stknum.pop();
                int num2 = stknum.top();
                stknum.pop();
                char op = stkope.top();
                stkope.pop();
                stknum.push(calculate(num2, num1, op));
            }
            stkope.pop(); // 弹出左括号
        }
        else if (isOperator(s[i]))
        { // 运算符计算
            while (!stkope.empty() && getPriority(stkope.top()) >= getPriority(s[i]))
            {
                // 运算符非空，且栈顶运算符优先级大于等于当前运算符优先级，计算
                int num1 = stknum.top();
                stknum.pop();
                int num2 = stknum.top();
                stknum.pop();
                char op = stkope.top();
                stkope.pop();
                stknum.push(calculate(num2, num1, op));
            }
            stkope.push(s[i]);
        }
    }

    while (!stkope.empty())
    {
        int num1 = stknum.top();
        stknum.pop();
        int num2 = stknum.top();
        stknum.pop();
        char op = stkope.top();
        stkope.pop();
        stknum.push(calculate(num2, num1, op));
    }

    return stknum.top();
}

int main()
{
    string s;
    while (cin >> s)
    {
        replace(s);
        cout << calculate(s) << endl;
    }
    return 0;
}
