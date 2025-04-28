#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B; cin>>A>>B;
    int n,m; cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> b_all(m+1);
    for(int i=1;i<=m;i++)cin>>b_all[i];
    // prepare b extended
    // cache damage per ai
    unordered_map<int,ll> cache;
    for(int i=0;i<n;i++){
        int ai=a[i];
        if(cache.find(ai)==cache.end()){
            int T = ai*B;
            vector<int> b(T+1);
            for(int t=1;t<=T;t++) b[t] = (t<=m?b_all[t]:0);
            // compute no-help damage
            ll dmg_no=0;
            int alive=ai;
            int hp_cur=B;
            for(int t=1;t<=T;t++){
                if(hp_cur>1) hp_cur--;
                else { alive--; hp_cur=B; }
                dmg_no += alive;
            }
            // DP saved
            const ll NEG = -(1LL<<60);
            vector<ll> cur(T+1, NEG), nxt;
            cur[0]=0;
            for(int j=0;j<ai;j++){
                nxt.assign(T+1, NEG);
                vector<ll> pref(T+1, NEG);
                pref[0]=cur[0];
                for(int t=1;t<=T;t++) pref[t]=max(pref[t-1], cur[t]);
                int min_t = (j+1)*B;
                int max_t = T - (ai-(j+1))*B;
                for(int t=min_t; t<=max_t; t++){
                    ll best = pref[t-B];
                    if(best<=NEG/2) continue;
                    ll w = b[t] ? (ai - (j+1)) : 0;
                    nxt[t] = best + w;
                }
                cur.swap(nxt);
            }
            ll saved = cur[T];
            if(saved<0) saved=0;
            ll dmg = dmg_no - saved;
            cache[ai]=dmg;
        }
        A -= cache[ai];
        if(A<=0){ cout<<"LOSE"; return 0; }
    }
    cout<<A;
    return 0;
}