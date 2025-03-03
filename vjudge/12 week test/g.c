#include<stdio.h>

int main()
{
    int n,a1,a2,a3,max=0;
    scanf("%d",&n);
    for(a3=n;a3>=max/3-1;a3--){
        for(a2=n;a2>=max/3-1;a2--){
            for(a1=n;a1>=max/3-1;a1--){
                if((a1+a2)%2==0&&(a2+a3)%3==0&&(a1+a2+a3)%5==0){
                    if(a1+a2+a3>max){
                        max=a1+a2+a3;
                    }
                }
            }
        }
    }
    printf("%d",max);
    return 0;
}