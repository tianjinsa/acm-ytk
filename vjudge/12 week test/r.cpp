#include<stdio.h>
long long x[1501];
int min(int a,int b)
{
    return a<b?a:b;
}
void sss(int n)
{
    int i2=0,i3=0,i5=0,xx=1;
    x[0]=1;
    for(int i=1;i<n;i++){
        xx=min(x[i2]*2,min(x[i3]*3,x[i5]*5));
        x[i]=xx;
        if(xx==x[i2]*2){
            i2++;
        }
        if(xx==x[i3]*3){
            i3++;
        }
        if(xx==x[i5]*5){
            i5++;
        }
    }
}
int main()
{
    int n;
    sss(1500);
    while(scanf("%d",&n)&&n)
    {
        printf("%lld\n",x[n-1]);
    }

    return 0;
}