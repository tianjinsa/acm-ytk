#include<stdio.h>
#include<string.h>
long long change(char ch[],int a)
{
    long long n=strlen(ch),xx=0;
    for(int i=0;i<n;i++){
        if(ch[i]-'0'>=a){
            return 0;
        }
        xx*=a;
        xx+=ch[i]-'0';
    }
    return xx;
}
int main()
{
    char ch[101],a[101],b[101];
    scanf("%s%s%s",a,b,ch);
    long long x,y,z;
    for(int i=2;i<=16;i++){
        if((x=change(a,i))&&(y=change(b,i))&&(z=change(ch,i))){
            if(x*y==z){
                printf("%d",i);
                return 0;
            }
        }
    }
    printf("0");
    return 0;
}