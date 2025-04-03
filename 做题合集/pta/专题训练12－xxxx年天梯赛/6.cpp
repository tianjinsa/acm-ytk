#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        bool fl=1;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]<='Z'&&s[i]>='A'&&(s[i]-s[i+1]==-1||abs(s[i]-s[i+1])==32))continue;
            if(s[i]<='z'&&s[i]>='a'&&(s[i]-s[i+1]==1||abs(s[i]-s[i+1])==32))continue;
            fl=0;
        }
        if(fl) cout<<'Y'<<endl;
        else cout<<'N'<<endl;
    }
    return 0;
}