#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        long long a[100];
        a[1]=1;
        a[2]=2;
        for(int i=3;i<=n;i++) {
            a[i]=a[i-1]+a[i-2];
        }
        printf("%lld\n",a[n]);
    }
    return 0;
}