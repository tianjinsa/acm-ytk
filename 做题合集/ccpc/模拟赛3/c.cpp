#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i < n;i++){
        cin>>a[i];
        int k=log2(a[i]);
        sum+=k;
    }
    
    double L=log2(2024.0);
    int b=ceil(sum/L);
    cout<<b<<endl;
    
    return 0;
}