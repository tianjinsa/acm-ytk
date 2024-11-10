#include<stdio.h>
#include<math.h>
double xy[301][3],tt,max,xxxx,yyyy,xxx,yyy;
int nn,ax;
double ss(double a,double b,double x,double y)
{
    return sqrt(pow(a-x,2)+pow(b-y,2));
}
void yuanxjs(double x1,double y1,double x2,double y2,int fl)
{
    if(fl==0){
        fl=-1;
    }
    xxx=(x1+x2)/2;
    yyy=(y1+y2)/2;
    double detx=sqrt(1-pow(ss(x1,y1,x2,y2)/2,2)),d=atan((x1-x2)/(y1-y2)*-1);
    double dy=sin(d),dx=cos(d);
    xxxx=detx*dx*fl+xxx;
    yyyy=detx*dy*fl+yyy;
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
    if(max>1.0999){
        x=(x*n-xy[ax][0])/(n-1);
        y=(y*n-xy[ax][1])/(n-1);
        xy[ax][2]=-n;
        return aim(x,y,n-1);
    }
    int xx=0,maxn=0;
    for(int i=0;i<nn;i++){
        for(int u=i+1;u<nn;u++){
            if(i!=u&&(xy[i][2]>=-n-2)&&(xy[u][2]>=-n-2)){
                if(ss(xy[i][0],xy[i][1],xy[u][0],xy[u][1])<=2.0001){
                    for(int g=0;g<=1;g++){
                        yuanxjs(xy[i][0],xy[i][1],xy[u][0],xy[u][1],g);
                        xx=0;
                        for(int p=0;p<nn;p++){
                            if(ss(xy[p][0],xy[p][1],xxxx,yyyy)<=1.0001){
                                xx++;
                            }
                        }
                        if(maxn<xx){
                            maxn=xx;
                        }
                    }
                }
                
            }
        }
    }
    return maxn;
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