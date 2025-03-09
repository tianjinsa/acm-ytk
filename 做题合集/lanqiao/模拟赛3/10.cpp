#include<bits/stdc++.h>
using namespace std;
bool sss(string &a,string &b){
    return a+b<b+a;
}
int main()
{
    vector<string>strs(4);
    for(int i=0;i<4;i++){
        cin>>strs[i];
    }
    sort(strs.begin(),strs.end(),sss);
    string ans;
    for(auto &s:strs){
        ans+=s;
    }
    
    cout<<ans<<endl;
    
    return 0;
}