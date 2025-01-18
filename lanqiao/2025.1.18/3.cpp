#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int h,m,t;
    scanf("%d%d%d",&h,&m,&t);
    m+=t;
    h+=m/60;
    m%=60;
    h%=24;
    printf("%d\n%d",h,m);
    return 0;
}