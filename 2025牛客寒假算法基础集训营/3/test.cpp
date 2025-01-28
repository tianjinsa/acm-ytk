#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
int a[MAXN];
int main()
{
    int n,k,sum;
    while(cin>>n>>k){
        sum = 0;
        
        for(int i=0;i<n;i++){
            a[i]=n%(i+1);
        }
        // sort(a,a+n);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        // for(int i=0;i<k;i++){
        //     sum+=a[i];
        // }
        // printf("%d\n",sum);
    }
    return 0;
}