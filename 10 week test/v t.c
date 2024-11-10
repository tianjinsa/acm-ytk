#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    while (n--)
    {
        int t;
        double nn=0,a,b,dev=0;
        t=1;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%*s %lf %lf",&a,&b);
            if(b<60||t==0){
                t=0;
                continue;
            }
            dev+=a*b;
            nn+=a;
        }
        if(t){
            printf("%.2lf\n",(double)dev/nn);
        }
        else{
            printf("Sorry!\n");
        }
        if(n){
            printf("\n");
        }
    }
    return 0;
}
