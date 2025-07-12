#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, K;
    cin>>n>>K;
    int diff[1005][1005];
    for(int t=0;t<n;t++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        diff[x1][y1]++;
        diff[x2][y1]--;
        diff[x1][y2]--;
        diff[x2][y2]++;
    }
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            if(i>0)diff[i][j]+=diff[i-1][j];
            if(j>0)diff[i][j]+=diff[i][j-1];
            if(i>0 && j>0)diff[i][j]-=diff[i-1][j-1];
        }
    }
    long long ans=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            if(diff[i][j]==K)ans++;
        }
    }
    cout<<ans;
    return 0;
}