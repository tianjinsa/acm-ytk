#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    long long a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    long long rsum[n+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            rsum[i]+=a[i][j];
        }
        rsum[i]+=rsum[i-1];
    }
    long long csum[m+1]={0};
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            csum[j]+=a[i][j];
        }
        csum[j]+=csum[j-1];
    }
    long long maxsum=LONG_LONG_MIN;
    long long xsum[n+1][m+1]={0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            xsum[i][j]=xsum[i-1][j]+xsum[i][j-1]-xsum[i-1][j-1]+a[i][j];
        }
    }
    for(int r1=2;r1<n;r1++){
        for(int r2=r1;r2<n;r2++){
            long long rall=rsum[r2]-rsum[r1-1];
            for(int c1=2;c1<m;c1++){
                for(int c2=c1;c2<m;c2++){
                    long long crall=csum[c2]-csum[c1-1];
                    long long tt=xsum[r2][c2]-xsum[r2][c1-1]-xsum[r1-1][c2]+xsum[r1-1][c1-1];
                    long long sum=rall+crall-tt;
                    maxsum=max(maxsum,sum);
                }
            }
        }
    }
    
    cout<<maxsum<<endl;
    
    return 0;
}
