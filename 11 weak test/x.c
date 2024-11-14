#include <stdio.h>
#include <stdlib.h>
long long apls(long long x,long long y)
{
    long long z=1;
    for(long long i=x;i>x-y;i--){
        z*=i;
    }
    return z;
}
int sss(int xx[],int yy[],int n)
{
    int tt=
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b,xx[101],yy[101],detx;
        scanf("%d%d",&a,&b);
        for(int i=0;i<a;i++){
            scanf("%d",&xx[i]);
            yy[i]=xx[i];
        }
        detx=sss(xx,yy,a);
        
    }
    return 0;
}