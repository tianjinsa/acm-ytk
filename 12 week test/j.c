#include<stdio.h>
long long cpls(int n,int k)//(下标，上标)
{
    if(k>n-k)k=n-k;
    long long xx=1;
    for(int i=0;i<k;++i){
        xx*=(n-i);
        xx/=(i+1);
    }
    return xx;
}
int main()
{
    int n,a[100001],xx[10010]={0},yy[10010]={0};
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        xx[a[i]]++;
    }
    long long sum=0;
    for(int i=0;i<n;i++){
        if(xx[a[i]]>1&&xx[2*a[i]]>1&&(yy[a[i]]==0||yy[2*a[i]]==0)){
            sum+=(cpls(xx[a[i]],2)*cpls(xx[2*a[i]],2));
            yy[a[i]]=1;
            yy[2*a[i]]=1;
            sum%=1000000007;
        }
        
    }
    
    printf("%lld\n",sum);
    return 0;
}