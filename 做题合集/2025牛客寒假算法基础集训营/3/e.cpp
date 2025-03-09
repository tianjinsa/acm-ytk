#include <bits/stdc++.h>
using namespace std;
long long anstt1,anstt2;
long long sss(const vector<long long>&L,const vector<long long>&R,double T){
    long long ans=0;
    int j=0;
    for(auto l:L){
        while(j<R.size()&&R[j]<=l)
            j++;
        int t=j;
        while(t<R.size()&&R[t]<=l+2.0*T)
            t++;
        ans+=(t-j);
    }
    return ans;
}

int main(){
    long long n,k;cin>>n>>k;
    vector<long long>L,R;
    for(int i=0;i<n;i++){
        long long p,v;cin>>p>>v;
        if(v==1)L.push_back(p);
        else R.push_back(p);
    }
    sort(L.begin(),L.end());
    sort(R.begin(),R.end());
    long long all=0;
    int j=0;
    for(auto r:R){
        while(j<(int)L.size()&&L[j]<r)j++;
        all+=j;
    }
    if(all<k){
        printf("No");
        return 0;
    }
    printf("Yes\n");
    double left=0,right=2e9;
    for(int i=0;i<51;i++){
        double mid=(left+right)/2.0;
        if((anstt1=sss(L,R,mid))>=k)
            right=mid;
        else
            left=mid;
    }
    printf("%lf",right);
    return 0;
}
