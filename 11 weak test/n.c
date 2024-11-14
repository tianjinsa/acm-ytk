#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a[100]={0},x,y;
        scanf("%d%d",&x,&y);
        a[x-1]=0;
        a[x]=1;
        for(int i=x+1;i<=y;i++){
            a[i]=a[i-1]+a[i-2];
        }
        printf("%d\n",a[y]);
    }
    
    return 0;
}