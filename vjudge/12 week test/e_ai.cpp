#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int q,e,i,d,a=23,b=28,c=33;
    scanf("%d%d%d%d",&q,&e,&i,&d);
    int x=(5544*q+14421*e+1288*i)%21252-d;
    if(x<=0){
        x+=21252;
    }
    printf("%d",x);
    return 0;
}