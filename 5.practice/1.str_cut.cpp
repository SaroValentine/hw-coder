/*
给定一个非空字符串S，其被N个‘-’分隔成N+1的子串，给定正整数K，要求除第一个子串外，其余的子串每K个字符组成新的子串，并用‘-’分隔。对于新组成的每一个子串，如果它含有的小写字母比大写字母多，则将这个子串的所有大写字母转换为小写字母；反之，如果它含有的大写字母比小写字母多，则将这个子串的所有小写字母转换为大写字母；大小写字母的数量相等时，不做转换。
输入描述:
输入为两行，第一行为参数K，第二行为字符串S。
输出描述:
输出转换后的字符串。
示例1
输入
3
12abc-abCABc-4aB@
输出
12abc-abc-ABC-4aB-@
说明
子串为12abc、abCABc、4aB@，第一个子串保留，后面的子串每3个字符一组为abC、ABc、4aB、@，abC中小写字母较多，转换为abc，ABc中大写字母较多，转换为ABC，4aB中大小写字母都为1个，不做转换，@中没有字母，连起来即12abc-abc-ABC-4aB-@
示例2
输入
12
12abc-abCABc-4aB@
输出
12abc-abCABc4aB@
说明
子串为12abc、abCABc、4aB@，第一个子串保留，后面的子串每12个字符一组为abCABc4aB@，这个子串中大小写字母都为4个，不做转换，连起来即12abc-abCABc4aB@

作者：yaozi
链接：https://leetcode.cn/circle/discuss/niKSMZ/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include<iostream>
#include<string>
using namespace std;
void reverse(string& str){
    // 统计大写字母个数
    int upCount = 0;
    int lowerCount = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            upCount++;
        }else if (str[i] >= 'a' && str[i] <= 'z'){
            lowerCount++;
        }
    }
    if(upCount > lowerCount){
        // 大写字母多，转换为大写
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= 'a' && str[i] <= 'z'){
                str[i] = str[i] - ('a' - 'A');
            }
        }
    }else if (upCount < lowerCount){
        // 小写字母多，转换为小写
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + ('a' - 'A');
            }
        }
    }
}
int main(){
    int n;
    while(cin >> n){
        string str;
        cin >> str;
        string res;
        int pos = 0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='-') {
                pos = i;
                break;
            }
            res += str[i];
        }
        // 去掉后面的所有 ‘-’ 字符
        for(int i=pos;i<str.size();i++){
            if(str[i] == '-'){
                str.erase(i,1);
            }
        }
        cout << "str=" << str << endl;
        int i = pos;
        for(;i<str.size();i+=n){
            if(i + n < str.size()){
                string tmp = str.substr(i,n);
                reverse(tmp);
                res = res + "-" + tmp;
            }
        }
        if(i > str.size()){
            string tmp = str.substr(i-n);
            reverse(tmp);
            res = res + "-" + tmp;
        }
        
        cout << res << endl;
    }
    return 0;
}