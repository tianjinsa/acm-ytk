#include<bits/stdc++.h>
using namespace std;
int b[1501]={0};
bool a[100000000]={0};
void ai_prime(int n)
{
    for(int i=2;i*i<=n;i++){
        if(a[i]==0){
            for(int j=i*i;j<n;j+=i){
                a[j]=1;
            }
        }
    }
}
void sss()
{
    int xx=0,x=0;
    a[1]=a[2]=a[3]=a[5]=1;

    while(1){
        x++;
        if(a[x]==0){
            goto to;
        }
        for(int i=7;i<=x/2;i++){
            if((a[i]==0&&x%i==0)){
                goto to;
            }
        }
        b[xx++]=x;
        
        if(xx==1501){
            break;
        }
        to:
    }
}
int main()
{
    int n;
    
    ai_prime(1000000);
    sss();
    while(scanf("%d",&n)&&n){
        printf("%d\n",b[n-1]);
    }
    return 0;
}