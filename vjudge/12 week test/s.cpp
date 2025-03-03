#include<stdio.h>
int n,abc[500];
void sss()
{
    for(n=1;n*n<=100000;n++){
        abc[n]=n*n;
    }
}
int main()
{
    sss();
    int a,b;
    while(scanf("%d%d",&a,&b)&&b!=0){
        int nn=0;
        for(int i=1;i<n;i++){
            if(a<=abc[i]&&abc[i]<=b){
                nn++;
            }
        }
        printf("%d\n",nn);
    }
    return 0;
}