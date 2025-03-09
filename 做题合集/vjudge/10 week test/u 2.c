#include<stdio.h>
int main()
{
    int a,n,x;
    while(scanf("%d",&a)!=EOF){
        int b[1010000]={0};
        n=(a+1)/2;
        for(int i=0;i<a;i++){
            scanf("%d",&x);
            if(++b[x]>=n){
                for(int q=i;q<a;q++){
                    scanf("%*d");
                }
                break;
            }
        }
        printf("%d\n",x);
    }
    return 0;
}