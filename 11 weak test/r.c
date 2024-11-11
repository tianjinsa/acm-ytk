#include <stdio.h>
long long apls(long long x,long long y)//(下标，上标)
{
    long long z=1;
    for(long long i=x;i>x-y;i--){
        z*=i;
    }
    return z;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        
        printf("%.2lf%%\n",/apls(a,a)*100);
    }
    return 0;
}
