#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char a[100]={0},b[100]={0},c[200]={0};
    scanf("%s",a);
    n=strlen(a);
    strcpy(c,a);
    strcat(c,a);
    
    for(int i=2;i<=n;i++){
        int temp=0;
        for(int j=n-1;j>=0;j--){
            int tt=(a[j]-'0')*i+temp;
            temp=tt/10;
            b[j]=tt%10+'0';
        }
        b[n]='\0';
        if(temp!=0||strstr(c,b)==0){
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}
