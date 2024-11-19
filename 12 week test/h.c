#include<stdio.h>
#include<stdbool.h>
short abb[1000000]={0};
void abc()
{
    for(int i=2;i*i<=1000000;i++)
    {
        if(abb[i]==0)
        {
            for(int j=i*i;j<1000000;j+=i)
            {
                abb[j]=1;
            }
        }
    }
}
int main()
{
    abc();
    int x,fl=0;
    while(scanf("%d",&x)&&x!=0){
        for(int i=3;i<=x/2+1;i+=2){
            if(abb[i]==0&&abb[x-i]==0){
                printf("%d = %d + %d\n",x,i,x-i);
                fl=1;
                break;
            }
        }
        if(fl==0){
            printf("Goldbach's conjecture is wrong\n");
        }
    }
    return 0;
}