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
        if(fabs(tt)<1e-8){
            x1=(-b)/(2*a);
            printf("x1=x2=%.5lf\n",x1);
        }
        else if(tt>0){
            x1=(-b+sqrt(tt))/(2*a);
            x2=(-b-sqrt(tt))/(2*a);
            printf("x1=%.5lf;x2=%.5lf\n",x1,x2);
        }
        else{
            x1=-b/(2*a);
            if(fabs(x1)<1e-8){
                x1=0;
            }
            x2=sqrt(-tt)/(2*a);
            printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",x1,x2,x1,x2);
        }
    }
    return 0;
}