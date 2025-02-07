#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--){
        int n,m;
        cin>>n>>m;
        long long a[n][m],b[n+m-1]={0},c[n+m-1]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                b[i+j]+=a[i][j];
                c[i-j+m-1]+=a[i][j];
            }
        }
        long long max1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum=b[i+j]+c[i-j+m-1]-a[i][j];
                if(sum>max1){
                    max1=sum;
                }
            }
        }
        cout<<max1<<endl;
    }
    return 0;
}