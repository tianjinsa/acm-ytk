#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp;//unordered_map
long long pos(int l,int r) {
    return (long long)l*200005+r;
}
int main()
{
    // bool abc[200000]={0};
    int n,q;
    scanf("%d%d",&n,&q);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    long long ans1=0,sum=0;
    for(int i=0;i<n;i++){
        sum=0;
        ans1=0;
        for(int j=i+1;j<n;j++){
            sum+=a[j-1];
            if(sum<a[j]){
                ans1+=a[j]-sum;
                sum+=a[j]-sum;
            }
            mp[pos(i,j)]=ans1;
        }
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        // if(abc[l-1]==0){
        //     abc[l-1]=1;
        //     int i=l-1;
        //     ans1=0;
        //     sum=0;
        //     for(int j=i+1;j<n;j++){
        //         sum+=a[j-1];
        //         if(sum<a[j]){
        //             ans1+=a[j]-sum;
        //             sum+=a[j]-sum;
        //         }
        //         mp[pos(i,j)]=ans1;
        //     }
        // }
        printf("%lld\n",mp[pos(l-1,r-1)]);
    }
    return 0;
}