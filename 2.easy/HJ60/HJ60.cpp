#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int num) {
    if (num <= 1) return false;  // 0和1不是质数

    int sqrtNum = static_cast<int>(sqrt(num));  // 对数值开平方，减少循环次数

    for (int i = 2; i <= sqrtNum; i++) {
        if (num % i == 0) {
            return false;  // 如果能整除，说明不是质数
        }
    }
    return true;  // 否则是质数
}
int main() {
    int a;
    while (cin >> a) {
        int num;
        for(num=a/2;num>=2;num--){
            if(isPrime(num) && isPrime(a-num)){
                printf("%d\n%d",num,a-num);
                break;
            }
        }
    }
    return 0;
}