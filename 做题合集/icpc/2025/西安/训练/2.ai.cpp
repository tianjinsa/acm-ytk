#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static inline unsigned long long gid64(ll x, ll y){
    return ( (unsigned long long)( (unsigned long long)(x) & 0xFFFFFFFFULL ) << 32 ) | ( (unsigned long long)(y) & 0xFFFFFFFFULL );
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n, m;
        string s;
        cin >> n >> m;
        cin >> s;
        vector<pair<ll,ll>> pref;
        ll x=0,y=0;
        pref.emplace_back(x,y); 
        for(char c: s){
            if(c=='U') y++;
            else if(c=='D') y--;
            else if(c=='L') x--;
            else x++;
            pref.emplace_back(x,y);
        }
        ll dx = x, dy = y; 

        ll ans = 0;
        if(dx==0 && dy==0){
            unordered_set<unsigned long long> st;
            st.reserve(pref.size()*2);
            for(auto &p: pref) st.insert(gid64(p.first, p.second));
            for(int i=0;i<m;i++){
                ll px, py; cin >> px >> py;
                if(st.count(gid64(px,py))) ans++;
            }
        } else {
            unordered_map<ll, unordered_map<ll, ll>> mp;
            mp.reserve(pref.size()*2);

            if(dx != 0){
                ll M = llabs(dx);
                for(auto &p: pref){
                    ll xi = p.first, yi = p.second;
                    ll key = xi*dy - yi*dx;
                    ll r = xi % M;
                    if(r<0) r += M;
                    auto &inner = mp[key];
                    if(inner.find(r)==inner.end()){
                        inner[r] = dx>0 ? xi : xi;
                    } else {
                        if(dx>0) inner[r] = max(inner[r], xi);
                        else inner[r] = min(inner[r], xi);
                    }
                }
                for(int i=0;i<m;i++){
                    ll px, py; cin >> px >> py;
                    ll key = px*dy - py*dx;
                    auto it = mp.find(key);
                    if(it==mp.end()) continue;
                    ll r = px % M; if(r<0) r += M;
                    auto it2 = it->second.find(r);
                    if(it2==it->second.end()) continue;
                    ll xi_best = it2->second;
                    if(dx>0){
                        if(xi_best <= px) ans++;
                    } else {
                        if(xi_best >= px) ans++;
                    }
                }
            } else {
                ll M = llabs(dy);
                for(auto &p: pref){
                    ll xi = p.first, yi = p.second;
                    ll key = xi*dy - yi*dx; 
                    ll r = yi % M;
                    if(r<0) r += M;
                    auto &inner = mp[key];
                    if(inner.find(r)==inner.end()){
                        inner[r] = dy>0 ? yi : yi;
                    } else {
                        if(dy>0) inner[r] = max(inner[r], yi);
                        else inner[r] = min(inner[r], yi);
                    }
                }
                for(int i=0;i<m;i++){
                    ll px, py; cin >> px >> py;
                    ll key = px*dy - py*dx;
                    auto it = mp.find(key);
                    if(it==mp.end()) continue;
                    ll r = py % M; if(r<0) r += M;
                    auto it2 = it->second.find(r);
                    if(it2==it->second.end()) continue;
                    ll yi_best = it2->second;
                    if(dy>0){
                        if(yi_best <= py) ans++;
                    } else {
                        if(yi_best >= py) ans++;
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}