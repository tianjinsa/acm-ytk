#include<stdio.h>
int main()
{
    long long n,i,a,b,max;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        max=0;
        for(long long g=a;g<=b;g++){
            i=1;
            n=g;
            while (n>1){
                if(n%2==1){
                    n=n*3+1;
                    i++;
                }
                else{
                    n/=2;
                    i++;
                }
            }
            if(max<i){
                max=i;
            }
        }
        printf("%lld %lld %lld\n",a,b,max);
    }
    return 0;
    
}