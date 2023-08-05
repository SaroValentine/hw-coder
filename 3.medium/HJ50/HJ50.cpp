#include <iostream>
using namespace std;
#include <string>
#include <stack>

//+就push -就push -1*val *就是与栈顶相乘  /就是与栈顶相除
//0==+  1==-  2==*  3==/
void stk_type(stack<int>&stk,int type,int val)
{
    if(type==0)
    stk.push(val);
    else if(type==1)
    stk.push(-1*val);
    else if(type==2)
    stk.top()*=val;
    else
    stk.top()/=val;
    return;
}

//计算算式，默认一开始是+  后面的根据前面的符号去改变type值
//括号类型根据评论区改了，将三种不同的括号类型同一变成为'('
int compute_str(string& str)
{
    int type=0;
    stack<char>c_stk;   //存放括号类型
    stack<int>stk;   //存放值的栈
    int cnt=0;
    int pos=0,str_size=str.size();
    while(pos<str_size)
    {
        int left=pos;
        if(str[pos]-'0'<0||str[pos]-'0'>9)   //如果部位数字值，则就是运算符和括号类型
        {
            //运算符类型判断
            if(str[pos]=='+')
            {
                type=0;
            }
            else if(str[pos]=='-')
            {
                type=1;
            }
            else if(str[pos]=='*')
            {
                type=2;
            }
            else if(str[pos]=='/')
            {
                type=3;
            }
            else   //因为有括号，因此需要算出括号内部的值再去通过stk_type函数去操作栈
            {
                c_stk.push('(');
                ++pos;
                while(pos<str_size&&!c_stk.empty())
                {
                    //统一视为'()'
                    if(str[pos]=='('||str[pos]=='{'||str[pos]=='[')
                    c_stk.push('(');
                    else if(str[pos]==')'||str[pos]=='}'||str[pos]==']')
                    c_stk.pop();
                    if(!c_stk.empty())
                    ++pos;
                }
                string tmp(str.begin()+left+1,str.begin()+pos);//取出括号内部的string
                stk_type(stk,type,compute_str(tmp));//算出来括号内部的值再去操作栈
            }
            ++pos;
        }
        else
        {
            while(pos<str_size&&str[pos]-'0'>=0&&str[pos]-'0'<=9)
            {
                ++pos;
            }
            string tmp(str.begin()+left,str.begin()+pos);
            int val=stoi(tmp);
            stk_type(stk,type,val);
        }
    }
    while(!stk.empty())  //这里就是将栈里面的值相加即可返回，具体参考leetcode 面试题 计算器
    {
        cnt+=stk.top();
        stk.pop();
    }    
    return cnt;    
}

int main() {
    string line;
    getline(cin,line);
    cout<<compute_str(line)<<endl;
    return 0;
}