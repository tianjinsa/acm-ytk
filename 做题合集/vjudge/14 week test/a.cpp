#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int a=1;
        for(int i=1;i<n;i++){
            a=(a+1)*2;
        }
        printf("%d\n",a);
    }
    return 0;
}