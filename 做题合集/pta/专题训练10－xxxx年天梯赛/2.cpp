#include<bits/stdc++.h>
using namespace std;
int cc=1,nn;
bool dfs(int x,string s){
    if(x==0){
        if(cc==nn){
            cout<<s<<endl;
            return 0;
        }
        cc++;
        return 1;
    }
    for(char c='z';c>='a';c--){
        bool t=dfs(x-1,s+c);
        if(!t)return 0;
    }
    return 1;
}
int main()
{
    int l,t;
    cin>>l>>nn;
    dfs(l,"");
    return 0;
}