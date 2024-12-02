#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int n;
    long long abc[3]={0};
    scanf("%d",&n);
    while(n--){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        long long i=1;
        abc[0]=0;
        abc[1]=1;
        a=pow(10,a+1);
        while(b){
            i++;
            abc[2]=(abc[0]+abc[1])%a;
            abc[0]=abc[1];
            abc[1]=abc[2];
            if(abc[2]%(a/10)==0&&abc[2]){
                printf(",%lld\n",i);
                b--;
            }
        }
        printf("-%lld\n",i);
    }
    return 0;
}