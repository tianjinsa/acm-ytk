#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

struct Record {
    ll a, b;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    cin >> T;
    while(T--){
        int n;
        ll c1, c2;
        cin >> n >> c1 >> c2;
        vector<Record> rec(n+1);
        for (int i = 1; i <= n; i++){
            cin >> rec[i].a >> rec[i].b;
        }
        // dp[i][0/1]: 最小代价，最后保留第 i 条记录，状态 0(不交换)或1(交换)
        vector<vector<ll>> dp(n+1, vector<ll>(2, INF));
        // 虚拟起点，下标 0，值 (0,0)
        // 遍历每个记录 i（1~n）
        for (int i = 1; i <= n; i++){
            for (int state = 0; state < 2; state++){
                // 当前记录转换后得分
                ll curA = (state==0 ? rec[i].a : rec[i].b);
                ll curB = (state==0 ? rec[i].b : rec[i].a);
                ll opCost = (state==0 ? 0 : c2);
                // 转移，自虚拟起点 j==0
                // 虚拟起点总是有效，因为 (0,0) <= (curA,curB)
                dp[i][state] = min(dp[i][state], (ll)(i - 1)*c1 + opCost);
                // 或从之前保留的记录 j (1 ≤ j < i)
                for (int j = 1; j < i; j++){
                    for (int prevState = 0; prevState < 2; prevState++){
                        if(dp[j][prevState]==INF) continue;
                        // j记录在 prevState 下的得分
                        ll prevA = (prevState==0 ? rec[j].a : rec[j].b);
                        ll prevB = (prevState==0 ? rec[j].b : rec[j].a);
                        if(prevA <= curA && prevB <= curB){
                            dp[i][state] = min(dp[i][state], dp[j][prevState] + (ll)(i - j - 1)*c1 + opCost);
                        }
                    }
                }
            }
        }
        // 最终答案考虑保留最后记录后删除其后的记录，以及全部删除的情况
        ll ans = (ll)n*c1; // 全删方案
        for (int i = 1; i <= n; i++){
            for (int state = 0; state < 2; state++){
                ans = min(ans, dp[i][state] + (ll)(n - i)*c1);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
