#include<bits/stdc++.h>
using namespace std;
map<int,map<int,double>>mp;
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--){
        int k;
        cin>>k;
        vector<int> arr(k);
        for(int i=0;i<k;i++){
            cin>>arr[i];
        }
        double tt=1.0/k;
        for(int i=0;i<k;i++){
            for(int j=i+1;j<k;j++){
                if((arr[i]<0&&arr[j]>0)||(arr[i]>0&&arr[j]<0)){
                    mp[arr[i]][arr[j]]+=tt;
                    mp[arr[j]][arr[i]]+=tt;
                }
            }
        }
    }
    int a,b;
    cin>>a>>b;
    bool fl1=0,fl2=0;
    vector<int>out1,out2;
    double max1=0,max2=0;
    for(auto [e,v]:mp[a]){
        if(v>max1){
            max1=v;
            fl1=0;
            out1.clear();
            out1.push_back(e);
            if(e==b)fl1=1;
        }
        else if(abs(v-max1)<1e-6){
            out1.push_back(e);
            if(e==b)fl1=1;
        }
    }
    for(auto [e,v]:mp[b]){
        if(v>max2){
            max2=v;
            fl2=0;
            out2.clear();
            out2.push_back(e);
            if(e==a)fl2=1;
        }
        else if(abs(v-max2)<1e-6){
            out2.push_back(e);
            if(e==a)fl2=1;
        }
    }
    if(fl1&&fl2){
        cout<<a<<' '<<b;
        return 0;
    }
    if(a<0)reverse(out2.begin(),out2.end());
    else reverse(out1.begin(),out1.end());
    for(auto i:out1){
        cout<<a<<' '<<i<<endl;
    }
    for(auto i:out2){
        cout<<b<<' '<<i<<endl;
    }
    return 0;
}