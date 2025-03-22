#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int fl[2]={0};
    vector<long long>x(n);
    for(int i=0;i<n;++i){
        cin>>x[i];
        fl[x[i]%2]++;
    }
    sort(x.begin(),x.end());
    if(fl[0]==0||fl[1]==0){
        printf("%d 2",x[0]);
        return 0;
    }
    int maxn=max(fl[0],fl[1]),xx=2,yy=(maxn==fl[0]?0:1);
    for(int i=3;i<(x[n-1]-x[0])/maxn&&i<x[n-maxn];i+=2){
        vector<int> a(i,0);
        for(auto tt:x){
            a[tt%i]++;
        }
        for(int j=0;j<i;j++){
            if(a[j]>maxn){
                maxn=a[j];
                xx=i;
                yy=j;
            }
        }
    }
    printf("%d %d",yy,xx);
    return 0;
}