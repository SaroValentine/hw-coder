#include<bits/stdc++.h>
using namespace std;

bool match(const char* s,const char* p){

    //两个字符串同时结束,返回true
    if((*p=='\0')&&(*s=='\0')){
        return true;
    }
     //两个字符串中有一个先结束，返回false
    if((*p=='\0')||(*s=='\0')){
        return false;
    }
    if(*p=='?'){//通配符为？时
        if(!isdigit(*s)&&!isalpha(*s)){//只能匹配数字或字母
            return false;
        }
        //匹配一个字符，从下一个位置开始继续匹配
        return match(s+1,p+1);
    }else if(*p=='*'){//通配符为！时
        while(*p=='*'){//多个*和一个*效果相同
            p++;
        }
        p--;
        //遇到*号，匹配0个（str+1,str1不用动），匹配1个（str和str1都往前移动1位），匹配多个（str不用动，str+1）
        return match(s,p+1) || match(s+1,p+1) ||  match(s+1,p);
    }else if(tolower(*p)==tolower(*s)){//不区分大小写
         //当前两字符相等，则进行下一个字符的匹配
        return match(s+1,p+1);
    }
    return false;//不满足上述三种情况，不匹配

}



int main(){
    string p,s;
    while(cin>>p>>s){
        bool res = match(s.c_str(),p.c_str());
        if(res){
            cout<<"true"<<endl;
        }else{
            cout<<"false"<<endl;
        }
    }
    return 0;
}
