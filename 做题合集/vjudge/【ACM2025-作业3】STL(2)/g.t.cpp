#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int d,k;
    if(!(cin>>d>>k)) return 0;
    vector<string> s(k);
    for(int i=0;i<k;i++) cin>>s[i];
    vector<int> mod(k), len(k);
    for(int i=0;i<k;i++){
        int m=0;
        for(char c : s[i]) m = ((long long)m*10 + (c - '0')) % d;
        mod[i] = m;
        len[i] = s[i].size();
    }
    vector<int> pow10(81);
    pow10[0] = 1 % d;
    for(int i=1;i<=80;i++) pow10[i] = (long long)pow10[i-1] * 10 % d;
    int N = 1<<k;
    vector<vector<long long>> dp(N, vector<long long>(d, 0));
    dp[0][0] = 1;
    for(int mask=0; mask<N; mask++){
        for(int r=0; r<d; r++){
            if(dp[mask][r]==0) continue;
            for(int i=0; i<k; i++){
                if(!(mask & (1<<i))){
                    int new_r = ((long long)r * pow10[len[i]] + mod[i]) % d;
                    dp[mask|(1<<i)][new_r] += dp[mask][r];
                }
            }
        }
    }
    cout<<dp[N-1][0];
    return 0;
}
