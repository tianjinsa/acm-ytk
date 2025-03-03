#include <stdio.h>

int main()
{
    long long a,m,n,s,i,mm[14]={0};
    while(scanf("%lld",&a)&&a!=0){
        if(mm[a]==0){
            m=a+1;
            n=2*a;
            while(1){
                s=0;
                for(i=0;i<a;i++){
                    s=(s+m-1)%(n-i);
                    if(s<a){
                        break;
                    }

                }
                if(i==a){
                    mm[a]=m;
                    break;
                }
                m++;
            }
        }
        printf("%lld\n",mm[a]);
    }
    return 0;
}