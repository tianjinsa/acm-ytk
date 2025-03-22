#include<bits/stdc++.h>
//using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        int b[m];
        bool fl=0;
        for(int i=0;i<m;i++){
            scanf("%d",&b[i]);
            if(b[i]==1){
                fl=1;
            }
        }
        if(fl){
            printf("-1\n");
            continue;
        }
        long long tt=1000000000;
        while(tt++){
            for(int i=2;i*i<=tt;i++){
                if(tt%i==0){
                    break;
                }
            }
            printf("%lld\n",tt);
            break;
        }
    }
    return 0;
}