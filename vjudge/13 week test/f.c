#include<stdio.h>
#include<string.h>
int nn=0;
long long change(char ch[])
{
    long long n=strlen(ch),xx=0;
    for(int i=0;i<n;i++){
        xx*=2;
        xx+=ch[i]-'0';
        nn+=ch[i]-'0';
    }
    return xx;
}
int main()
{
    char ch[101];
    while(scanf("%s",ch)&&ch[0]!='0'){
        nn=0;
        printf("%lld\n",change(ch)*2-nn);
    }
    return 0;
}