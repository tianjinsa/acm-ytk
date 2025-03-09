#include<bits/stdc++.h>
using namespace std;

long long con(long long n){
    if(n<2) return 0;
    long long count=n/2;
    long long power=4;
    while(power<=n){
        count--;
        power*=2;
    }
    return count;
}
long long sss(long long k){
    long long left=2,right=4000000000000000000;
    while(left<right){
        long long mid=left+(right-left)/2;
        if(mid%2==1)
            mid--;
        
        long long cnt=con(mid);
        if(cnt<k){
            left=mid+2;
        }
        else{
            right=mid;
        }
    }
    return left;
}

int main(){
    int N;
    cin >> N;
    while(N--){
        long long k;
        cin >> k;
        long long result=sss(k);
        cout << result << '\n';
    }
    return 0;
}