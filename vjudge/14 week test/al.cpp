#include<stdio.h>
long long ssss(int x,int y)
{   
    long long z=1;
    for(int i=x;i>x-y;i--){
        z*=i;
    }
    return z;
}
int main()
{
    int n,x,a,b,c,d,xx;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        xx=0;
        x-=1;
        if(x==1||x==0){
            printf("1\n");
            continue;
        }
        if(x==2){
            printf("2\n");
            continue;
        }
        d=a=x/2;
        b=x%2;
        
        for(int f=0;f<=d;f++){
            c=(a<b)?a:b;
            xx+=ssss(a+b,c)/ssss(c,c);
            a--;
            b+=2;
        }
        printf("%d\n",xx);
    }
    return 0;
}