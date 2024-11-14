#include <stdio.h>

int main()
{
    int n,a[101],max=0,b[101]={0},c[101]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for (int i=0;i<n;i++){
        b[i]=1;
        for (int j=0;j<i;j++){
            if (a[j]<a[i]&&b[j]+1>b[i]){
                b[i]=b[j]+1;
            }
        }
    }
    for (int i =n-1;i>=0;i--){
        c[i] =1;
        for (int j=n-1;j>i;j--){
            if (a[j]<a[i]&&c[j]+1>c[i]){
                c[i]=c[j]+1;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(b[i]+c[i]-1>max){
            max=b[i]+c[i]-1;
        }
    }
    printf("%d",n-max);
    return 0;
}