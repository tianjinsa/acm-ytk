#include<bits/stdc++.h>
using namespace std;
long long ans=0;
void chack(string &s);
void ss(const int &n,string s){
    if(s.size() == 24){  // 当字符串长度达到24时检查
        chack(s);
        return;
    }
    
    if(s.size() < 24) {  // 只有长度小于24才继续添加字符
        ss(n, s+'0');
        ss(n, s+'1');
    }
}
void chack(string &s){
    // 使用前缀和计算连续5个位置中1的个数
    int a[25]={0};
    for(int i=0;i<s.size();i++){
        a[i] = (i > 0 ? a[i-1] : 0) + (s[i]-'0');
    }
    
    // 检查任意5个连续位置是否有超过3个1
    for(int i=0;i<=s.size()-5;i++){
        int ones = a[i+4] - (i > 0 ? a[i-1] : 0);
        if(ones > 3){
            return;  // 不满足条件，直接返回
        }
    }
    ans++;  // 满足条件，计数加1
}
int main()
{
    ss(24,"");  // 24是目标长度
    cout << ans << endl;
    return 0;
}
