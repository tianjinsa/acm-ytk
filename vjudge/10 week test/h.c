#include<stdio.h>
int sss(int n)
{
    if((n%4==0&&n%100!=0)||n%400==0){
        return 1;
    }
    return 0;
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    while(n--){
        int xx=1;
        scanf("%d%d",&a,&b);
        while(!sss(a)){
            a++;
        }
        for(;xx<=b;a+=4){
            if(sss(a)){
                xx++;
            }
        }
        printf("%d\n",a-4);
    }
    return 0;
}