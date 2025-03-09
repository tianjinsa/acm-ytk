#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n,sum;
    while(scanf("%d",&n)!=EOF){
        sum=0;
        for(int i=n-1;i>=0;i--){
            printf("%d%c",sum,i==0?'\n':' ');
            sum+=i;
        }
    }
    
    return 0;
}