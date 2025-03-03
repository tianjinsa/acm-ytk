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
    int k=3,m;
    for(m=3;m<=4500;m++){
        n=6;
        k=3;
        //scanf("%d%d%d",&n,&k,&m);
        char s[100000]="AAAAAA";
        //scanf("%s",s);
        int x=0;
        for(int i=0;i<m-1;i++){
            x=(x+k)%n;
            caru(s,x+1,sss(s[x]));
            x++;
            //printf("%s\n",s);
        }
        x=(x+k)%n;
        printf("%d,%d\n1,%d\n",m,sss(s[x])-'A'+1,sss(s[x])-'A'+1);
    }
    return 0;
}