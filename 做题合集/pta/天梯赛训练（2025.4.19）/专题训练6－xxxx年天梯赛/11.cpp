#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,k,M;
    cin>>N>>k>>M;
    
    vector<double>ss;
    
    for(int i=0;i<N;i++){
        double sum=0;
        int t,max=-1,min=111;
        for(int j=0;j<k;j++){
            cin>>t;
            sum+=t;
            if(t>max)max=t;
            if(t<min)min=t;
        }
        ss.push_back((sum-max-min)/(k-2));
    }
    sort(ss.begin(),ss.end());
    k=ss.size()-M;
    if(k<0)k=0;
    bool fl=0;
    for(int i=k;i<ss.size();i++){
        if(fl)cout<<" ";
        fl=1;
        cout<<fixed<<setprecision(3)<<ss[i];
    }
    
    return 0;
}