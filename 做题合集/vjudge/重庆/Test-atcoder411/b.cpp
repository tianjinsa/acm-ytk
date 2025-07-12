#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    vector<int> d(N-1);
    for(int i=0;i<N-1;i++)
        cin>>d[i];
    vector<int> p(N+1);
    p[1]=0;
    for(int i=2;i<=N;i++)
        p[i]=p[i-1]+d[i-2];
    for(int i=1;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            cout<<p[j]-p[i]<<(j==N?"":" ");
        }
        cout<<'\n';
    }
    return 0;
}