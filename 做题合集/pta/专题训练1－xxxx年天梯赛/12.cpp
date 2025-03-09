#include<bits/stdc++.h>
using namespace std;

int ss(string s,int l,int r){
    while(l >= 0 && r<s.length()&&s[l]==s[r]){
        l--;
        r++;
    }
    return r-l-1;
}
int main()
{
    string s;
    getline(cin,s);
    int maxl=0;
    for(int i=0;i<s.length();i++){
        maxl=max(maxl,max(ss(s,i,i),ss(s,i,i+1)));
    }
    
    cout<<maxl<<endl;
    return 0;
}