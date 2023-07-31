#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { 
        vector<int> arr;
        int tmp;
        for(int i=0;i<a;i++){
            scanf("%d",&tmp);
            arr.push_back(tmp);
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<b;i++){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}