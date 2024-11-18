#include<stdio.h>
#include<stdbool.h>
bool abb[2024]={0};
void abc()//生成素数表,艾氏筛素数
{
    for(int i=2;i<2024;i++)
    {
        if(abb[i]==0)
        {
            for(int j=i*i;j<2024;j+=i)
            {
                abb[j]=1;
            }
        }
    }
}
int main()
{
    abc();
    int x;
    scanf("%d",&x);
    if(x%2||x<6){
        printf("Error!\n");
        return 0;
    }
    for(int i=3;i<=x/2;i+=2)
    {
        if(abb[i]==0&&abb[x-i]==0)
        {
            printf("%d=%d+%d\n",x,i,x-i);
        }
    }
    return 0;
}