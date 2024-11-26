#include<stdio.h>
#include<string.h>

int main()
{
	double xx=0,yy=1;
    char a[100];
    int len;
    gets(a);
    len=strlen(a);
    if(a[len-1]=='\n'){
    	len--;
	}
    for(int i=2;i<len;i++){
    	yy/=8;
    	xx+=yy*(a[i]-'0');
    	
	}
	printf("%s [8] = %.45g [10]",a,xx);
	return 0;
}