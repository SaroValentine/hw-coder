#include <iostream>
using namespace std;

int main() {
    string str;
    int a;
    while (cin >> str >> a) { // 注意 while 处理多个 case
        for(int i = 0;i < a && i< str.size() ;i++){
            cout << str[i] << "" ;
        }
    }
    return 0;
}