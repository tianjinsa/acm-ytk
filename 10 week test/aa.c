#include <stdio.h>
#include<math.h>

int main()
{
    int a,b;
    double PI=2*asin(1);
    while (scanf("%d%d",&a,&b)&&(a!=0||b!=0))
    {
        printf("%.3lf\n",pow(a*a*a-6*b/PI,1.0/3));
    }
    
    return 0;
}