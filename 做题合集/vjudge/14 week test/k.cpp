#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n",(long long)1<<(a-b));
    }
    return 0;
}