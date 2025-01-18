#include<bits/stdc++.h>
//using namespace std;

int main()
{
    char c[10000];
    int a=0;
    while(~scanf("%s",c)){
        a+=strlen(c);
    }
    printf("%d",a);
    return 0;
}