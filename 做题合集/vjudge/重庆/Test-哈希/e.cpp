#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin>>S;
    int n=S.size();
    const unsigned long long base=(1ULL<<7)-1;
    vector<unsigned long long> H(n+1), P(n+1);
    P[0]=1;
    for(int i=1;i<=n;i++) P[i]=P[i-1]*base;
    for(int i=1;i<=n;i++) H[i]=H[i-1]*base+(unsigned long long)(S[i-1]);
    int m;
    cin>>m;
    while(m--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        if(r1-l1!=r2-l2){
            cout<<"No\n";
            continue;
        }
        if(H[r1]-H[l1-1]*P[r1-l1+1]==H[r2]-H[l2-1]*P[r2-l2+1])cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}