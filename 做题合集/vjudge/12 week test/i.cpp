#include<stdio.h>
#include<stdbool.h>
void ai_prime(bool a[],int n)
{
    for(int i=2;i*i<=n;i++){
        if(a[i]==0){
            for(int j=i*i;j<n;j+=i){
                a[j]=1;
            }
        }
    }
}
int main()
{
    int a;
    bool abb[1<<16]={0};
    ai_prime(abb,1<<16);
    while(scanf("%d",&a)&&a){
        int nn=0;
        for(int i=3;i<=a/2;i+=2){
            if(abb[i]==0&&abb[a-i]==0){
                nn++;
            }
        }
        printf("%d\n",nn);
    }
    return 0;
}