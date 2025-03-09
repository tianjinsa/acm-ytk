#include<bits/stdc++.h>
//using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    while(N--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n<=m){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            for(int i=0;i<m;i++)printf("a");
            for(int i=m;i<n;i++){
                printf("%c",'b'+((i*2-m)/m)%26);
            }
            printf("\n");
        }
    }
    return 0;
}