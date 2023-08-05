#include<iostream>
using namespace std;

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        int len1=s1.size(),len2=s2.size();
        // 如果有一个字符串为空，则直接输出另一个字符串的长度
        if(len1==0||len2==0){
            cout<<len1+len2<<endl;
            continue;
        }
        // dp[i][j]表示s1的前i个字符和s2的前j个字符的编辑距离
        int dp[len1+1][len2+1];
        // 初始化,s2为空时，s1的编辑距离
        for(int i=0;i<=len1;i++){  
            dp[i][0]=i;
        }
        // 初始化,s1为空时，s2的编辑距离
        for(int j=0;j<=len2;j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    // 比较 dp[i-1][j],dp[i][j-1] 
                    // 得到由s1的前i-1个字符转换为s2的前j个字符的编辑距与由s1的前i个字符转换为s2的前j-1个字符的编辑距离最小值
                    int temp=min(dp[i-1][j],dp[i][j-1]);
                    // 再与由s1的前i-1个字符转换为s2的前j-1个字符的编辑距离最小值比较
                    dp[i][j]=min(temp,dp[i-1][j-1])+1;
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
}