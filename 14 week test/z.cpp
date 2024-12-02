#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    long long a[51]={0};
    a[1]=3;
    a[2]=6;
    a[3]=6;
    for(int i=4;i<=50;i++){
        a[i]=(a[i-1]/3+pow(-1.0,i*1.0))*6;
    }
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",a[n]);
    }
    return 0;
}