#include<stdio.h>
#include<math.h>
double PI;
int main(){
    PI=4*atan(1);
    int n,yy;
    double x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf%lf",&x,&y);
        yy=(int)(PI*(x*x+y*y)/100+1);
        printf("Property %d: This property will begin eroding in year %d.\n",i,yy);
    }
    printf("END OF OUTPUT.");
    return 0;
}