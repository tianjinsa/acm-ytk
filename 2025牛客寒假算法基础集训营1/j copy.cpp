#include<bits/stdc++.h>
//using namespace std;
int a[600005]={0};
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int tt,b[n]={0},t=0;
    for(int i=0;i<n;i++){
        scanf("%d",&tt);
        if(!a[tt]){
            b[t++]=tt;
        }
        a[tt]++;
    }
    int ans=0;
    for(int i=0;i!=t;++i){
        for(int j=i+1;j!=t;++j){
            if(gcd(b[i],b[j])==(b[i]^b[j])){
                ans+=a[b[i]]*a[b[j]];
            }
        }
    }
    printf("%d",ans);
    return 0;
}