#include<stdio.h>
int a,b;
int fff[1000]={0,1,1},xx;
void ff(int n)
{
    if(n==1||n==2){
        xx=1;
    }
    else{
        for(int i=3;i<=n;i++){
            xx=fff[i]=(a*fff[i-1]+b*fff[i-2])%7;
            if(i>4&&fff[i]==fff[4]&&fff[i-1]==fff[3]){
                xx=fff[(n-5)%(i-4)+5];
                break;
            }
        }
    }
}
int main()
{
    int n;
    while(scanf("%d%d%d",&a,&b,&n)&&(a!=0||b!=0||n!=0)){
        ff(n);
        printf("%d\n",xx);
    }
    return 0;
}