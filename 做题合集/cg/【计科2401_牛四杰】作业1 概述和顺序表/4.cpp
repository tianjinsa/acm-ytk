#include<bits/stdc++.h>
using namespace std;

bool ss(vector<int>& a,int s,int t){
    int k = 0;
    bool fl=0;
    for(int i = 0;i <(int)a.size();++i){
        if(a[i] < s || a[i] > t){
            a[k++] = a[i];
            fl=1;
        }
    }
    a.resize(k);
    return fl;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int s,t;
    cin>>s>>t;
    if(s > t){
        cout<<"s or t error!";
        return 0;
    }
    ss(a,s,t);
    cout<<"{ ";
    for (int i=0;i<a.size();i++) {
        cout<<a[i]<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}