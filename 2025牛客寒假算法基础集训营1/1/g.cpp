#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long a[n],sum=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    if(sum!=(n*n+n)/2){
        printf("-1");
        return 0;
    }
    sort(a,a+n);
    sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>i+1)
            sum+=a[i]-i-1;
    }
    printf("%lld",sum);
    return 0;
}