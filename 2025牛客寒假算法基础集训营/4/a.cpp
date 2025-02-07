#include<bits/stdc++.h>
using namespace std;
 
const long long MOD = 1000000007;
 
int main(){
    
    int T;
    cin >> T;
    while(T--){
        long long n;
        cin >> n;
        vector<int> a(n), b(n);
        long long ans1=0,ans2=1;
        cin >> a[0] >> b[0];
        for(int i=1; i<n; i++){
            cin >> a[i] >> b[i];
            for(int j=a[i-1];j<=b[i-1];j++){
                for(int q=a[i];q<=b[i];q++){
                    ans1+=abs(j-q);
                }
            }
            ans2=lcm(ans2,(b[i-1]-a[i-1]+1)*(b[i]-a[i]+1));
        }
        long long tt=gcd(ans1,ans2);
        ans1/=tt,ans2/=tt;
        printf(",%lld,%lld\n",ans1,ans2);
    }
    
    return 0;
}