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
        long long tt=1;
        while(tt++){
            fl=1;
            for(int i=0;i<m;i++){
                if((b[i]>=tt&&b[i]%tt==0)||(tt>b[i]&&tt%b[i]==0)){
                    fl=0;
                    break;
                }
            }
            if(fl){
                printf("%d\n",tt);
                break;
            }
        }
    }
    return 0;
}