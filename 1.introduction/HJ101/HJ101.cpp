#include <cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int a, b;
    while (cin >> a ) { 
        vector<int>arr(a);
        for(int i=0;i<a;i++){
            scanf("%d",&arr[i]);
        }
        int flag;
        scanf("%d",&flag);
        auto f= [flag](int a,int b)  { 
            if(flag==1) 
                return a>b;
            return a<=b;
        };  
        sort(arr.begin(),arr.end(),f);
        for(int i=0;i<arr.size();i++){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}
