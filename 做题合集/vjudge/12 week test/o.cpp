#include<stdio.h>

int main()
{
    int n,nn=0;
    scanf("%d",&n);
    double average;
    int a[n][1001]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][0]);
        for(int j=1;j<=a[i][0];j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        average=0;
        nn=0;
        for(int j=1;j<=a[i][0];j++){
            average+=a[i][j];
        }
        average/=a[i][0];
        for(int j=1;j<=a[i][0];j++){
            if(a[i][j]>average){
                nn++;
            }
        }
        printf("%.3lf%%\n",(double)nn/a[i][0]*100);
    }
    
    return 0;
}