#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    while(n--){
        int a,b,c;
        scanf("%d-%d %d",&a,&b,&c);
        mp[a]+=c;
    }
    int max=0,maxn=0;
    for(auto& [a,b]:mp) {
        if(b>max){
            max=b;
            maxn=a;
        }
    }
    cout<<maxn<<' '<<max;
    return 0;
}