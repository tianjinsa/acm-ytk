#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while (n--){
        double a,b,c,x1,x2,tt;
        scanf("%lf%lf%lf",&a,&b,&c);
        tt=b*b-4*a*c;
        if(tt>0){
            x1=(-b+sqrt(tt))/(2*a);
            x2=(-b-sqrt(tt))/(2*a);
            if(x1<x2){
                double t=x1;
                x1=x2;
                x2=t;
            }
            long long  xxx=100000*x1;yyy=100000*x2;
            if(xxx==yyy){
            goto to;
            }
            printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
        }
        else if(b*b==4*a*c){
            x1=(-b)/(2*a);
            to:
            printf("x1=x2=%.5lf\n",x1);
        }
        else{
            x1=(-b)/(2*a);
            x2=sqrt(-tt)/(2*a);
            printf("x1=%.5lf+%.5lfi;x2=%.5lf-%.5lfi\n",x1,x2,x1,x2);
        }
    }
    return 0;
}