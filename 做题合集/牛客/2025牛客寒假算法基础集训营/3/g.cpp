#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long sss(long long a){
    for(long long i=2;i<n;i++){
        if((n-a)%(i)!=0||((n-a)/(i)<a)){
            return i-1;
        }
    }
    return n-1;
}
int main()
{
    while(cin>>n>>k){
        long long sum=0;
        long long tt;
        if(k>(n-1)/2-n/3){
            sum+=(n/3+1)*((n-1)/2-n/3)+((n-1)/2-n/3)*((n-1)/2-n/3-1)/2;
            k-=(n-1)/2-n/3;
        }
        else{
            sum+=((n-1)/2-k+1)*k+k*(k-1)/2;
            printf("%lld",sum);
            continue;
        }
        for(long long i=n/3;i>=1&&k;--i){
            tt=min(sss(i),k);
            sum+=i*tt;
            k-=tt;
        }
        printf("%lld",sum);
    }
    return 0;
}