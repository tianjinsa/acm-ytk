#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    int m;
    scanf("%d",&m);
    while(m--){
        int n,t;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&t);
            mp[t]++;
        }
        if(mp.size()!=2||mp.begin()->second!=next(mp.begin())->second){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
        mp.clear();
    }
    return 0;
}