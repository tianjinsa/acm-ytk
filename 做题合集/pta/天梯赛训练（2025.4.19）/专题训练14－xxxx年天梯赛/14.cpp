#include<bits/stdc++.h>
using namespace std;
unordered_map<int,map<int,int>>mp1,mp2;
const int MAX_N=1000000000;
int main()
{
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        mp1[i][MAX_N]=i;
        mp1[i][0]=i;
        mp2[i][MAX_N]=i;
        mp2[i][0]=i;
    }
    long long sum=n*(n+1)*(2*n+1)/6;
    while(m--){
        char c;
        int x1,x2,y;
        cin>>c>>x1>>x2>>y;
        auto &at2=prev(mp2[x1].lower_bound(y))->second;
        auto &at1=mp1[x1].upper_bound(y)->second;
        auto &bt2=prev(mp2[x2].lower_bound(y))->second;
        auto &bt1=mp1[x2].upper_bound(y)->second;
        sum-=at1*at2+bt1*bt2;
        sum+=at1*bt2+bt1*at2;
        if(c=='+'){
            mp2[x1][y]=bt2;
            mp2[x2][y]=at2;
            mp1[x1][y]=at1;
            mp1[x2][y]=bt1;
            swap(prev(mp1[x1].lower_bound(y))->second,prev(mp1[x2].lower_bound(y))->second);
            swap(mp2[x1].upper_bound(y)->second,mp2[x2].upper_bound(y)->second);
        }
        else{
            mp2[x2].erase(y);
            mp2[x1].erase(y);
            mp1[x2].erase(y);
            mp1[x1].erase(y);
            swap(prev(mp1[x1].lower_bound(y))->second,prev(mp1[x2].lower_bound(y))->second);
            swap(mp2[x1].upper_bound(y)->second,mp2[x2].upper_bound(y)->second);
        }
        cout<<sum<<endl;
    }
    
    return 0;
}