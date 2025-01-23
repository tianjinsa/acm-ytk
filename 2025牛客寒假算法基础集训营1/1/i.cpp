#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    int m;
    scanf("%d",&m);
    while(m--){
        int n,k;
        scanf("%d%d",&n,&k);
        
        int a[n],b[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        if(k<n){
            printf("-1\n");
            continue;
        }
        while(1){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=gcd(a[i],b[i]);
                if(sum>k){
                    break;
                }
            }
            if(sum==k){
                for(int i=0;i<n;i++){
                    printf("%d ",b[i]);
                }
                printf("\n");
                break;
            }
            next_permutation(b,b+n);
        }
        
    }
    return 0;
}