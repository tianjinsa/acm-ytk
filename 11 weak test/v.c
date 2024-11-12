#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        double a,b,c,x1,x2;
        int tt;
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
            printf("x1=%.5f;x2=%.5f\n",x1,x2);
        }
        else if(tt==0){
            x1=(-b)/(2*a);
            printf("x1=x2=%.5f\n",x1);
        }
        else{
            x1=(-b)/(2*a);
            x2=sqrt(-tt)/(2*a);
            printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",x1,x2,x1,x2);
        }
    }
    return 0;
}