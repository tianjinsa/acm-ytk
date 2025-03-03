#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF){
        while(n--){
            int t=1;
            double nn=0,dev=0,a,b;
            scanf("%d",&m);
            while(m--)
            {
                scanf("%*s %lf %lf",&a,&b);
                if(b<60){
                    t=0;
                }
                dev+=a*b;
                nn+=a;
            }
            if(t){
                printf("%.2lf\n",dev/nn);
            }
            else{
                printf("Sorry!\n");
            }
            if(n){
                printf("\n");
            }
        }
    }
    return 0;
}
