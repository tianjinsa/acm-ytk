#include<stdio.h>
int main()
{
    int a,n,x[1010000];
    while(scanf("%d",&a)!=EOF){
        int b[1010000]={0};
        n=(a+1)/2;
        for(int i=0;i<a;i++){
            scanf("%d",&x[i]);
        }
        for(int i=0;i<a;i++){
            if(++b[x[i]]>=n){
                printf("%d\n",x[i]);
            }
        }
    }
    return 0;
}