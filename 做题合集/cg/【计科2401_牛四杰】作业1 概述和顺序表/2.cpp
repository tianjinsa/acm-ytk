#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    bool fl=1;
    for(int i=0;i<s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-2-i])
        {
            fl=0;
            break;
        }
    }
    if(fl) cout<<s.size()-1;
    else cout<<"no";
    return 0;
}