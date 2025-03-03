#include <stdio.h>
#include <stdlib.h>
int ks(int x,int y)
{
    if(x<y){
        return y;
    }
    return x;
}
int qs(int x,int y)
{
    if(x==y||x==0||y==0){
        return 1;
    }
    return 2;
}
int cs(int x,int y)
{
    if(x==0||y==0){
        return 1;
    }
    return 2;
}
int es(int x,int y)
{
    if(x==y){
        return 1;
    }
    if((x+y)%2==0){
        return 2;
    }
    return 0;
}
int main()
{
    int n,ki,qi,car,en;
    char x1,xx,y1,yy;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c%c %c%c",&x1,&y1,&xx,&yy);
        xx=abs((x1-'a'+1)-(xx-'a'+1));
        yy=abs((y1-'0')-(yy-'0'));
        if(xx||yy){
            ki=ks(xx,yy);
        qi=qs(xx,yy);
        car=cs(xx,yy);
        en=es(xx,yy);
        printf("%d %d %d %s\n",ki,qi,car,en?((en==1)?"1":"2"):"Inf");
        }
        else{
            printf("0 0 0 0\n");
        }
    }
    return 0;
}