#include<stdio.h>
#include<math.h>
double xy[301][2],xxxx,yyyy;
int nn;
double ss(double a,double b,double x,double y)
{
    return sqrt(pow(a-x,2)+pow(b-y,2));
}
void yuanxjs(double x1,double y1,double x2,double y2,int fl)
{
    if(fl==0){
        fl=-1;
    }
    xxxx=(x1+x2)/2;
    yyyy=(y1+y2)/2;
    double detx=sqrt(1-pow(ss(x1,y1,x2,y2)/2,2)),d=atan((x1-x2)/(y1-y2)*-1);
    double dy=sin(d),dx=cos(d);
    xxxx+=detx*dx*fl;
    yyyy+=detx*dy*fl;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&nn);
        for(int i=0;i<nn;i++){
            scanf("%lf%lf",&xy[i][0],&xy[i][1]);
        }
        int xx=0,maxn=1;
        for(int i=0;i<nn;i++){
            for(int u=i+1;u<nn;u++){
                if(ss(xy[i][0],xy[i][1],xy[u][0],xy[u][1])<=2){
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
        printf("%d\n",maxn);
    }
    return 0;
}