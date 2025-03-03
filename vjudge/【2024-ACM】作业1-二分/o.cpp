#include<bits/stdc++.h>
using namespace std;
int m;
bool ss(vector<int> &a,int x){
    int nn=1,tt=a[0];
    for(int i=1; i<a.size(); i++){
        if(a[i]-tt>=x){
            tt=a[i];
            nn++;
        }
    }
    return nn>=m;
}
int main()
{
    int n;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=0,r=a[n-1]-a[0];
    int cc=32;
    while(cc--&&l<r){
        int mid=l+(r-l+1)/2;
        if(ss(a,mid)){
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << l << endl;
    return 0;
}