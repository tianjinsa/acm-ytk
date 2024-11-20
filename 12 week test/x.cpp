#include<stdio.h>
#include<iostream>
using namespace std;
int a[10]={0},b[10000][10]={0},xx=0;
void sss(int n,int nn)
{
    for(a[nn]=1;a[nn]<=3;a[nn]++){
        if(nn==9&&a[0]+a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]==n){
            for(int i=0;i<10;i++){
                b[xx][i]=a[i];
            }
            xx++;
        }
        else if(nn<9){
            sss(n,nn+1);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    if(10<=n&&n<=30){
        sss(n,0);
        printf("%d\n",xx);
        for(int i=0;i<xx;i++){
            for(int j=0;j<10;j++){
                printf("%d ",b[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("0");
    }
    return 0;
}