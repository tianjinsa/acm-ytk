#include <stdio.h>
#include <string.h>

int main()
{
    char a[1002],b[1002],res[2003];
    scanf("%s %s",a,b);
    int i=strlen(a)-1,j=strlen(b)-1,carry=0,idx=0;
    while(i>=0||j>=0||carry){
        int x=(i>=0)?(a[i--]-'0'):0;
        int y=(j>=0)?(b[j--]-'0'):0;
        int sum=x+y+carry;
        carry=sum/10;
        res[idx++]=(sum % 10)+'0';
    }
    for(int k=0;k<idx/2;k++){
        char tmp=res[k];
        res[k]=res[idx-1-k];
        res[idx-1-k]=tmp;
    }
    res[idx]='\0';
    int start=0;
    while(res[start]=='0'&&start<idx-1)start++;
    printf("%s\n",res+start);
    return 0;
}