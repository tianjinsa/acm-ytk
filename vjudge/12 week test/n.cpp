#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d", &n);
    long long a[2]={0},x[n][n];
    memset(x,0,sizeof(x));
    a[0]=1;
    a[1]=n/2+1;
    x[a[0]-1][a[1]-1]=1;
    for(int i=2;i<=n*n;i++){
        if(a[0]==1&&a[1]!=n){
            a[0]=n;
            a[1]++;
            x[a[0]-1][a[1]-1]=i;
        }
        else if(a[1]==n&&a[0]!=1){
            a[1]=1;
            a[0]--;
            x[a[0]-1][a[1]-1]=i;
        }
        else if(a[0]==1&&a[1]==n){
            a[0]++;
            x[a[0]-1][a[1]-1]=i;
        }
        else if(x[a[0]-2][a[1]]==0){
            a[0]--;
            a[1]++;
            x[a[0]-1][a[1]-1]=i;
        }
        else{
            a[0]++;
            x[a[0]-1][a[1]-1]=i;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            printf("%lld ",x[i][j]);
        }
        printf("%lld\n",x[i][n-1]);
    }
    return 0;
}