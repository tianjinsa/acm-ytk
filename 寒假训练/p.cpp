#include<bits/stdc++.h>
int a[100000];
int main()
{
    int n=0,l=1;
    scanf("%d",&n);
    a[0]=0;
    a[1]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=l;++j)
        {
            a[j]=a[j]*i;
            a[j]=a[j-1]/10+a[j];
            a[j-1]=a[j-1]%10;
            if(a[j]>=10&&j>=l)l++;
        }
    }
    for(int i=l;i>=1;--i)
        printf("%d",a[i]);
    return 0;
}