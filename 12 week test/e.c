#include<stdio.h>
int main()
{
    int p,e,i,d,xx;
    scanf("%d%d%d%d",&p,&e,&i,&d);
    xx=d+1;
    while((xx-p)%23){
        xx++;
    }
    while((xx-e)%28){
        xx+=23;
    }
    while((xx-i)%33){
        xx+=23*28;
    }
    printf("%d",xx-d);
    return 0;
}