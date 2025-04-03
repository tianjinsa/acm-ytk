#include<bits/stdc++.h>
using namespace std;
map<int,bool> mp;
int main()
{
    int n;
    scanf("%d",&n);
    int out[n],a,b=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(mp[a]){
        }else{
            out[b++]=a;
            mp[a]=1;
        }
    }
    printf("%d\n",b);
    sort(out,out+b);
    for(int i=0;i<b;i++){
        printf("%d ",out[i]);
    }
    return 0;
}