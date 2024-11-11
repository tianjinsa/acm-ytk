#include<stdio.h>
#include<string.h>
int main()
{
    int n,xx=0;
    char a[100];
    fgets(a, 100, stdin);
    n=strlen(a);
    if(a[n-1]=='\n')
    {
        a[n-1]='\0';
        n--;
    }
    for(int i=0;i<n/2;i++)
    {
        if('a'<=a[i]&&a[i]<='z')
        {
            a[i]=a[i]-'a'+'A';
        }
        if('a'<=a[n-i-1]&&a[n-i-1]<='z')
        {
            a[n-i-1]=a[n-i-1]-'a'+'A';
        }
        if(a[i]!=a[n-i-1])
        {
            xx=1;
            break;
        }
    }
    if(xx){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return 0;
}