#include<stdio.h>
#include <string.h>
char sss(char x)
{
    if(x=='Z')
        return 'A';
    return x+1;
}
/* int caru(char a[],int x,char y,int n)
{
    for(int i=n-1;i>=x;i--){
        a[i+1]=a[i];
    }
    a[x]=y;
    n++;
    return n;
} */
void caru(char *a, int x, char y, int *n) {
    memmove(a + x + 1, a + x, (*n - x) * sizeof(char));
    a[x] = y;
    (*n)++;
}
int main()
{
    int k,xx,nn,n,xn;
    long long m;
    while(scanf("%d%d%lld",&n,&k,&m)!=EOF){
        nn=1;
        xn=n;
        int a[n+2];
        for(int i=0;i<n;i++){
            a[i]=i;
        }
        char s[n+1],b[(n+m)/3];
        scanf("%s",s);
        int x=0;
        for(int i=0;i<m-1;i++){
            x=(x+k)%n;
            for(int j=xn-1;j>=0;j--){
                if(a[j]<=x){
                    break;
                }
                a[j]++;
            }
            //caru(s,x+1,sss(s[x]));
            x++;
            n++;
        }
        x=(x+k)%n;
        a[xn]=n;
        n=xn;
        for(int j=n-1;j>=0;j--){
            if(a[j]<=x){
                xx=j;
                break;
            }
        }
        b[0]=s[xx];
        for(int i=0;i<n;i++){
            a[i]=i;
        }
        x=0;
        for(int i=0;i<m;i++){
            x=(x+k)%n;
            if((a[xx]<=x&&x<a[xx+1])||(a[xx]<=x&&a[xx]>a[xx+1])){
                caru(b,x-a[xx]+1,sss(b[x-a[xx]]),&nn);
            }
            for(int j=xn-1;j>=0;j--){
                if(a[j]<=x){
                    break;
                }
                a[j]++;
            }
            x++;
            n++;
        }
        x--;
        printf("%d\n",b[x-a[xx]+1]-'A'+1);
    }
    return 0;
}