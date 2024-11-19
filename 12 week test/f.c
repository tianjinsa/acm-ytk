#include<stdio.h>
#include<math.h>
int main()
{
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%d\n",(int)(log10(b)/log10(a)));
    return 0;
}