#include<stdio.h>
#include<math.h>
int main()
{
    long long a,b,sum,t=0;
    while(scanf("%lld%lld",&a,&b)&&(a||b)){
        if(t){
            printf("\n");
        }
        t=a;
        sum=sqrt((double)2*b);
        for(long long i=sum;i>=1;i--){
            sum=(b-i*(i+1)/2)/i+1;
            if(sum+i-1>t){
                break;
            }
            if(sum*i+i*(i-1)/2==b){
                printf("[%lld,%lld]\n",sum,sum+i-1);
            }
        }
    }
    return 0;
}