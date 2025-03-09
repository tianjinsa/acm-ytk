#include<bits/stdc++.h>
using namespace std;
long long ans=0;
void chack(string &s);
void ss(string s){
    if(s.size()==24){
        chack(s);
    }
    else{
        ss(s+'0');
        ss(s+'1');
    }
}
void chack(string &s){
    int a[25]={0};
    for(int i=0;i<s.size();i++){
        a[i] = (i > 0 ? a[i-1] : 0) + (s[i]-'0');
    }
    for(int i=0;i<=s.size()-5;i++){
        int ones = a[i+4] - (i > 0 ? a[i-1] : 0);
        if(ones > 3){
            return;
        }
    }
    ans++;
}
int main()
{
    ss("");
    cout << ans << endl;
    return 0;
}