/*
https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=1&ru=/exam/oj/ta&qru=/exam/oj/ta&sourceUrl=%2Fexam%2Foj%2Fta%3FtpId%3D37&difficulty=1&judgeStatus=undefined&tags=&title=
*/
#include <iostream>
using namespace std;

int main() {
    int num;
    while (cin >> num) { // 注意 while 处理多个 case
        int sum = 0 ;
        int hash[10]={0};
        while(num){
            if(hash[num%10]==0){
                sum = sum*10 + num%10;
                hash[num%10] = 1;
            }
            num/=10;
        }
        cout << sum << endl;
    }
}
