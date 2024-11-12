#include <stdio.h>
int dd(int m,int d)
{
    int mm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    for(int i=0;i<m-1;i++){
        sum+=mm[i];
    }
    sum+=d;
    return sum;
}
int main()
{
    int m1,m2,d1,d2,n,xx;
    long long a;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%lld%d%d",&m1,&d1,&a,&m2,&d2);
        xx=dd(m2,d2)-dd(m1,d1);
        for(int i=0;i<xx;i++){
            a*=2;
        }
        printf("%lld\n",a);
    }
    return 0;
}