#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,x,fl;
    while(scanf("%d%d",&n,&m)&&n!=0){
        fl=0;
        int a[n];
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&x);
                a[j]+=x;
                if(a[j]==m){
                    fl=1;
                }
            }
        }
        if(fl){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }
    return 0;
}