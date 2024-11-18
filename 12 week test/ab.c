#include <stdio.h>
int main()
{
    int n,ll=2;
    scanf("%d",&n);
    int a[1001]={0},b[1001]={0};
    a[1]=1;
    for(int i=1;i<=n;i++){
        int temp=0;
        for(int j=1;j<=ll;j++){
            a[j]=a[j]*i+temp;
            temp=a[j]/10;
            a[j]=a[j]%10;
            if(j==ll&&temp>0){
                ll++;
            }
        }
        temp=0;
        for(int j=1;j<=ll;j++){
            b[j]=b[j]+a[j]+temp;
            temp=b[j]/10;
            b[j]=b[j]%10;
            if(j==ll&&temp>0){
                ll++;
            }
        }
    }
    int k;
    for(int i=1000;i>=0;i--){
        if (b[i]!=0){
            k=i;
            break;
        }
    }
    for(int i=k;i>0;i--){
        printf("%d",b[i]);
    }
    printf("\n");
    return 0;
}
