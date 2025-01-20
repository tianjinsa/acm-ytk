#include<bits/stdc++.h>
//using namespace std;
int main()
{
    char abc[5000];
    scanf("%s",abc);
    int n=0;
    for(int i=0;abc[i]!='\0';i++){
        n+=abc[i]-'0';
    }
    n%=9;
    if(!n){
        n=9;
    }
    printf("%d",n);
    return 0;
}