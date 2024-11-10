#include<stdio.h>
#include<math.h>
double xy[301][3],tt,max,del=1.0999;
int nn,ax;
double ss(double a,double b,double x,double y)
{
    return pow(pow(a-x,2)+pow(b-y,2),0.5);
}
int aim(double x,double y,int n)
{
    max=0;
    for(int i=0;i<nn;i++){
        if(xy[i][2]>=0){
            tt=ss(x,y,xy[i][0],xy[i][1]);
            if(tt>max){
                max=tt;
                ax=i;
            }
        }
    }
    if(max>del){
        x=(x*n-xy[ax][0])/(n-1);
        y=(y*n-xy[ax][1])/(n-1);
        xy[ax][2]=-1;
        return aim(x,y,n-1);
    }
    n=0;
    for(int i=0;i<nn;i++){
        tt=ss(x,y,xy[i][0],xy[i][1]);
        if(tt<=1.0001){
            n++;
        }
    }
    return n;
}
int main()
{
    double xx,yy;
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        nn=n;
        xx=0;yy=0;
        if(n<=0){
            del=1.0999;
        }
        else{
            del=1.00019;
        }
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&xy[i][0],&xy[i][1]);
            xx+=xy[i][0];
            yy+=xy[i][1];
            xy[i][2]=1;
        }
        xx/=n;
        yy/=n;
        n=aim(xx,yy,n);
        printf("%d\n",n);
    }
    return 0;
}