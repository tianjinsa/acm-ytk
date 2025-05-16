#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
long long n;
long long ccc(){
    long long ans=0;
    for(long long i=0;i<n;i++){
        long long minn=n*n;
        for(long long j=0;j<n;j++){
            minn=min(minn,(long long)a[i*n+j]);
        }
        if(minn<=n){
            ans++;
        }
    }
    return ans;
}
long long ss(long long i){
    long long sum = 1;
    for(long long j=1; j<=i; j++){
        sum *= j;
    }
    return sum;
}
int main()
{
    cin>>n;
    a.resize(n*n);
    for(long long i=0;i<n*n;i++){
        a[i]=i+1;
    }
    map<long long,long long>mp;
    for(long long i=0;i<ss(n*n);i++){
        mp[ccc()]++;
        next_permutation(a.begin(), a.end());
    }
    for(auto [key, value] : mp) {
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    return 0;
}