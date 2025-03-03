#include<stdio.h>
int a=1,b=1;
int fff[1000]={7,11},xx;
void ff(int n)
{
    if(n==0){
        xx=7;
    }
    else if(n==1){
        xx=11;
    }
    else{
        for(int i=2;i<=n;i++){
            xx=fff[i]=(a*fff[i-1]+b*fff[i-2])%9;
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
    while(scanf("%d",&n)!=EOF){
        ff(n);
        if(xx%3){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
    }
    return 0;
}