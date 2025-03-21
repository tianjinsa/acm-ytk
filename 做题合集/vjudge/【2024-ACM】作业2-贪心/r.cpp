#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    double sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    int t=0;
    for(int i=0;i<n-1;i++){
        t+=a[i].first;
        sum+=t;
    }
    
    bool fl=0;

    for(int i=0;i<n;i++){
        if(fl)cout<<' ';
        fl=1;
        cout<<a[i].second+1;
    }
    
    cout<<endl<<fixed<<setprecision(2)<<sum/n<<endl;

    return 0;
}