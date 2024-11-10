#include<stdio.h>
#include<math.h>
int main() {
long long  n,m;
    while (scanf_s("%lld%lld",&n,&m)&&(n||m)){
    long long t;
        t=sqrt(2*m);
        long long i;
        for(i=t;i>=1;i--){
            long long a;
            a=(m-i*(i+1)/2)/i;
            if(a+i>n){
                break;
            }
            if ((a*i+i*(i+1)/2)==m){
                printf("[%lld,%lld]\n",a+1,a+i);
            }
        }
        printf("\n");
    }
}