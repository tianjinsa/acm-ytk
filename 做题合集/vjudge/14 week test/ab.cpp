#include <stdio.h>

int main()
{
    int n;
    long long a[40][2];
    while(scanf("%d",&n)!=EOF)
    {
        
        a[1][0]=2;
        a[1][1]=1;
        for(int i=2;i<=n;i++){
            a[i][0]=a[i-1][0]*2+a[i-1][1]*2;
            a[i][1]=a[i-1][0];
        }
        printf("%lld\n",a[n][1]+a[n][0]);
    
    }
    return 0;
}