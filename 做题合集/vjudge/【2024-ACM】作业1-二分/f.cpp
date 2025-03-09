#include<bits/stdc++.h>
using namespace std;
bool sss(vector<int> &a,int m,int x){
    int nn=0,tt=0;
    for(int i=1;i<=a.size()-1;i++){
        if(a[i]-tt<x){
            nn++;
        } else{
            tt=a[i];
        }
    }
    
    return nn<=m;
}

int main(){
    int L,N,M;
    cin>>L>>N>>M;
    vector<int> a(N+2);
    a[0]=0;
    for(int i=1;i <= N;i++){
        cin>>a[i];
    }
    a[N+1]=L;
    int l=1,r=L;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(sss(a,M,mid)){
            l=mid;
        } else{
            r=mid-1;
        }
    }
    cout<<l;
    return 0;
}