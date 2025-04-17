#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,p,ans=0;
    cin>>n>>p;
    vector<int>v(n,0);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        v[i]=t;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        int a = v[i];
        long long l=abs(a-p);
        long long r=p+a;
        long long ll=upper_bound(v.begin()+i+1,v.end(),l)-v.begin();
        long long rr=lower_bound(v.begin()+i+1,v.end(),r)-v.begin();
        long long nn=rr-ll;
        
        if(nn>0)
            ans+=nn;
    }
    
    cout<<ans;
    return 0;
}