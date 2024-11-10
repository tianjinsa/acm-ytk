#include <stdio.h>
int sss(int a,int b)
{
    int xx[100000]={1},yy=0,n=1;
    while(1){
        yy=(yy+a)%b;
        if(xx[yy]&&n==b){
            return 1;
        }
        if(++xx[yy]>1){
            return 0;
        }
        n++;
    }
}
int main()
{
    int a,b,i=0;
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        if(i){
            printf("\n\n");
        }
        printf("%10d%10d     %s",a,b,sss(a,b)?"Good Choice":"Bad Choice");
        i=1;
    }
    
    return 0;
}