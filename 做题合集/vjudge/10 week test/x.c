#include <stdio.h>

int main()
{
    long long a,b;
    while (scanf("%llX %llX",&a,&b)!=EOF)
    {
        if(a+b>=0){
        printf("%llX\n",(a+b));}
        else{
        printf("-%llX\n",-(a+b));}
        
    }
    
    return 0;
}