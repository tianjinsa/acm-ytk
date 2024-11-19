#include<stdio.h>

int main()
{
    int a,b,t;
    scanf("%d%d",&a,&b);
    char x[30]={0};
    getchar();
    for(int i=a-1;i>=0;i--){
        scanf("%c",&x[i]);
    }
    getchar();
    for(int i=a;i<=b-1;i++){
        scanf("%c",x[i]);
    }
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int t=x[a-i];
        x[a-i]=x[a-i+1];
        x[a-i+1]=t;
    }
    return 0;
}
lcm