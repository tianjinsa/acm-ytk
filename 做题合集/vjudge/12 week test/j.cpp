#include<stdio.h>
long long cpls(int x,int k)
{
    return (k==1?x:x*(x-1)/2)%1000000007;
}
int main()
{
    int n,a,xx[10010]={0},yy[10010]={0},max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        xx[a]++;
        if(a>max){
            max=a;
        }
    }
    long long sum=0;
    for(int i=2;i<=max;i++){
        if(xx[i]>1){
            if(i%2==0&&xx[i/2]>1){
                sum+=cpls(xx[i],2)*cpls(xx[i/2],2)%1000000007;
                sum%=1000000007;
            }
            for(int j=1;j<=i/2&&i-j!=j;j++){
                if(xx[j]>0&&xx[i-j]>0){
                    sum+=cpls(xx[i],2)*cpls(xx[j],1)*cpls(xx[i-j],1)%1000000007;
                    sum%=1000000007;
                }
            }
        }
    }
    printf("%lld\n",sum);
    return 0;
}