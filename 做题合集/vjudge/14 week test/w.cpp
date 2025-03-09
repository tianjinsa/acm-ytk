#include<bits/stdc++.h>
//using namespace std;
char a[1001][1000];
void ff()
{
    strcpy(a[0],"0");
    strcpy(a[1],"1");
    for(int i=2;i<=1000;i++)
    {
        int tt=0;
        int len1=strlen(a[i-1]);
        int len2=strlen(a[i-2]);
        for(int j=0;j<len1||j<len2||tt;j++)
        {
            int d1=(j<len1)?a[i-1][j]-'0':0;
            int d2=(j<len2)?a[i-2][j]-'0':0;
            int sum=d1+d2+tt;
            a[i][j]=(sum%10)+'0';
            tt=sum/10;
        }
    }
    for(int i=0;i<=1000;i++)
    {
        int len=strlen(a[i]);
        for(int j=0;j<len/2;j++)
        {
            char t=a[i][j];
            a[i][j]=a[i][len-j-1];
            a[i][len-j-1]=t;
        }
    }
}
int main()
{
    int n;
    ff();
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=39){
            printf("%s\n",a[n]);
        }
        else{
            printf("%c%c%c%c...%c%c%c%c\n",a[n][0],a[n][1],a[n][2],a[n][3],a[n][strlen(a[n])-4],a[n][strlen(a[n])-3],a[n][strlen(a[n])-2],a[n][strlen(a[n])-1]);
        }
    }
    return 0;
}