#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int m,d,month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d%d",&m,&d);
    if(m>12||month[m]<d){
        printf("no");
    }
    else{
        printf("yes");
    }
    return 0;
}