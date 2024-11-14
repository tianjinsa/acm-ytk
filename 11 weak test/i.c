#include <stdio.h>
#include<math.h>
int main()
{
    long long a,b,s,x1,x2;
    while(scanf("%llde%lld",&a,&b)!=EOF&&a!=0){
        while(b--){
            a*=10;
        }
        s=1;
        x1=x2=1;
        while(!(x1<=a&&a<x2)){
            x1=s;
            s*=2;
            x2=s;
        }
        printf("%lld\n",(a-x1)*2+1);
    }
    
    return 0;
}