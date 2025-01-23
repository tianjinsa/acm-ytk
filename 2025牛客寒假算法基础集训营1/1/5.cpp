#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    scanf("%d",&m);
    while(m--){
        int n,t;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ans=0;
        if(a[0]==a[n-1]){
            printf("%d\n",n/2);
            continue;
        }
        for(int i=0;i<n/2;i++){
            ans+=abs(a[i]-a[n/4]);
        }
        for(int i=n/2;i<n;i++){
            ans+=abs(a[i]-a[n/2+n/4]);
        }
        printf("%d\n",ans);
    }
    return 0;
}