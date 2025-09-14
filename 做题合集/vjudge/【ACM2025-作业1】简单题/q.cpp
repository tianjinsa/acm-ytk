#include<bits/stdc++.h>
using namespace std;

char g(char c)
{
    if(c>='0'&&c<='9')return c;
    if(c=='A'||c=='B'||c=='C')return '2';
    if(c=='D'||c=='E'||c=='F')return '3';
    if(c=='G'||c=='H'||c=='I')return '4';
    if(c=='J'||c=='K'||c=='L')return '5';
    if(c=='M'||c=='N'||c=='O')return '6';
    if(c=='P'||c=='R'||c=='S')return '7';
    if(c=='T'||c=='U'||c=='V')return '8';
    if(c=='W'||c=='X'||c=='Y')return '9';
    return '0';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    
    map<string,int> m;
    
    for(int i=0;i<n;++i)
    {
        string s,t;
        cin>>s;
        
        for(char c:s)
        {
            if(c=='-')continue;
            t+=g(c);
        }
        
        t.insert(3,"-");
        m[t]++;
    }
    
    vector<pair<string,int>> r;
    
    for(auto const& p:m)
    {
        if(p.second>1)
        {
            r.push_back(p);
        }
    }
    
    if(r.empty())
    {
        cout<<"No duplicates.\n";
    }
    else
    {
        for(auto const& p:r)
        {
            cout<<p.first<<" "<<p.second<<"\n";
        }
    }
    
    return 0;
}
