#include<stdio.h>
int n;
char sss(char x)
{
    if(x=='Z')
        return 'A';
    return x+1;
}
void caru(char a[],int x,char y)
{
    for(int i=n-1;i>=x;i--){
        a[i+1]=a[i];
    }
    a[x]=y;
    n++;
}
int main()
{
    int k,m,xx;
    while(scanf("%d%d%d",&n,&k,&m)!=EOF){
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=i;
        }
        char s[n+m];
        scanf("%s",s);
        int x=0;
        for(int i=0;i<m-1;i++){
            x=(x+k)%n;
            for(int j=n-1;j>=0;j++){
                if(a[j]<=x){
                    break;
                }
                a[j]++;
            }
            //caru(s,x+1,sss(s[x]));
            x++;
        }
        x=(x+k)%n;
        for(int j=n-1;j>=0;j++){
            if(a[j]<x){
                xx=j;
                break;
            }
        }
        for(int i=0;i<m-1;i++){
            x=(x+k)%n;
            //caru(s,x+1,sss(s[x]));
            x++;
        }
        printf("%d\n",sss(s[x]));
    }
    return 0;
}