#include<stdio.h>

int main()
{
    int n,x=0,a,b,max,min;
    scanf("%d",&n);
    scanf("%d%d",&a,&b);
    x+=a+b;
    if(a>b){
        max=a;
        min=b;
    }
    else{
        max=b;
        min=a;
    }
    for(int i=3;i<=n;i++){
        scanf("%d",&a);
        x+=a;
        if(a>max){
            max=a;
        }
        if(a<min){
            min=a;
        }
        printf("%.2lf\n",1.0*(x-max-min)/(i-2));
    }
    return 0;
}