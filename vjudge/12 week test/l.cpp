#include<stdio.h>

int main()
{
    long long n,m,xx=0,yy=0,min;
    scanf("%lld%lld", &n, &m);
    if(n<m){
        min=n;
    }
    else{
        min=m;
    }
    int a[n+1]={0},b[m+1]={0};
    for(int i=1;i<=n;i++){
        a[i]=n-i+1;
    }
    for(int i=1;i<=m;i++){
        b[i]=m-i+1;
    }
    for(int i=1;i<=min;i++){
        xx+=a[i]*b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            yy+=a[i]*b[j];
        }
    }
    printf("%lld %lld",xx,yy-xx);
    return 0;
}