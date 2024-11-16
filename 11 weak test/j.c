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
    int k,m;
    scanf("%d%d%d",&n,&k,&m);
    char s[100100000];
    scanf("%s",s);
    int x=0;
    for(int i=0;i<m-1;i++){
        x=(x+k)%n;
        caru(s,x+1,sss(s[x]));
        x++;
        //printf("%s\n",s);
    }
    x=(x+k)%n;
    printf("%c\n",sss(s[x]));
    return 0;
}