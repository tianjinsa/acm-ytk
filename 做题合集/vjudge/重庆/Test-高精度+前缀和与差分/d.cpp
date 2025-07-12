#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,K,B;
    cin>>N>>K>>B;
    vector<int> broken(N+1,0);
    for(int i=0;i<B;i++){
        int x;
        cin>>x;
        broken[x]=1;
    }
    int cnt=0;
    for(int i=1;i <= K;i++)
        cnt+=broken[i];
    int ans=cnt;
    for(int i=K + 1;i <= N;i++){
        cnt+=broken[i];
        cnt-=broken[i-K];
        ans=min(ans,cnt);
    }
    cout<<ans;
    return 0;
}