#include<bits/stdc++.h>
using namespace std;
bool ss(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
}
int sea(vector<pair<int,int>>& a,int r,int x){
    int ans=-1,l=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid].second<x){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    int N;
    cin>>N;
    vector<pair<int,int>>a(N);
    for(int i=0;i<N;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),ss);
    vector<int> dp(N);
    dp[0]=a[0].second-a[0].first+1;
    for(int i=1;i<N;i++){
        int ndp=dp[i-1];
        int j=sea(a,i-1,a[i].first);
        int ydp=a[i].second-a[i].first+1;
        if(j>=0){
            ydp+=dp[j];
        }
        dp[i]=max(ndp,ydp);
    }
    cout<<dp[N-1];
    return 0;
}