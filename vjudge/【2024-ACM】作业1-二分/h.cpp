#include<bits/stdc++.h>
using namespace std;

int main()
{
    int nn=0;
    vector<int>l(5,0);
    for(auto it=l.begin();it!=l.end();++it)
        cin>>*it;
    int t;
    for(int i=0;i<5;i++) {
        t=l[i]/3;
        nn+=l[i]%3;
        l[i]=t;
        l[(i+4)%5]+=t;
        l[(i+1)%5]+=t;
    }
    for(auto i:l)
        cout<<i<<' ';
    cout<<'\n'<<nn;
    return 0;
}