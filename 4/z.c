#include<stdio.h>
long long cx,vc,vx;
double ccc(double a)
{
    if(a>cx){
        return 1.0*cx/vc+(a-cx)/vx;
    }
    return a/vc;
}
int main()
{
    long long xxc[120]={0},n,ct,vr,ll;
    double time[120],tt,xtx;
    while(scanf("%lld",&ll)!=EOF){
        scanf("%lld%lld%lld%lld%lld%lld",&n,&cx,&ct,&vr,&vc,&vx);
        for(int i=1;i<=n;i++){
            scanf("%lld",&xxc[i]);
        }
        xxc[n+1]=ll;
        for(int i=1;i<=n+1;i++){
            double min=999999999;
            for(int f=0;f<i;f++){
                tt=ccc(1.0*xxc[i]-xxc[f])+ct;
            
                if(min>time[f]+tt){
                    min=time[f]+tt;
                }
            }
            time[i]=min;
        }
        
        if(time[n+1]-ct<1.0*ll/vr){
            printf("What a pity rabbit!\n");
        }
        else{
            printf("Good job,rabbit!\n");
        }
    }
    return 0;
}