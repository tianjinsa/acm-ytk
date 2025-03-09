#include<bits/stdc++.h>
using namespace std;
int sss(const string a,const string b) {
    int n=a.size(),m=b.size();
    int dp[2][10001]={0};
    for(int i=1;i<=n;i++){
        int tt=i%2;
        dp[tt][0]=0;
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[tt][j]=dp[!tt][j-1]+1;
            }
            else{
                dp[tt][j]=max(dp[!tt][j],dp[tt][j-1]);
            }
        }
    }
    return dp[n%2][m];
}
int main()
{
    string a,b;
    cin>>a>>b;
    cout<<sss(a,b);
    return 0;
}