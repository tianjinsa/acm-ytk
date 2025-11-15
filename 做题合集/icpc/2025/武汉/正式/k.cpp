#include <bits/stdc++.h>
using namespace std;
#define read_fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }

    if (!all_of(cnt.begin(), cnt.end(), [&](int x)
                { return x % 2 == 0; }))
    {
        cout << -1 << endl;
        return;
    }
    vector<pair<int, int>> op;
    unordered_map<int, set<pair<int,int>>> id;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            id[a[i]].insert({i , -1});
            id[b[i]].insert({i , -2});
        }
    }

    
    long long ans = 0;
    for(int u = 1;u <= n; u++){
        if(a[u] != b[u]) {
            auto itb = id[a[u]].upper_bound({u , 0});
            auto ita = id[b[u]].upper_bound({u , 0});
            auto [xb , tb] = *itb;
            auto [xa , ta] = *ita;
            ans += min(xb , xa) - u;
            
            if(xb < xa){
                if(tb == -1){
                    id[a[u]].erase(itb);
                    id[b[u]].insert({xb , -1});
                    op.push_back({xb , u});
                    swap(a[xb] , b[u]);
                }else{
                    id[a[u]].erase(itb);
                    id[b[u]].insert({xb , -2});
                    op.push_back({xb , xb});
                    op.push_back({xb , u});
                    op.push_back({xb , xb});
                    swap(b[u] , b[xb]);

                }
            }else{
                 if(ta == -2){
                    id[b[u]].erase(ita);
                    id[a[u]].insert({xa , -2});
                    op.push_back({u , xa});
                    swap(a[u] , b[xa]);
                }else{
                    id[b[u]].erase(ita);
                    id[a[u]].insert({xa , -1});
                    op.push_back({xa , xa});
                    op.push_back({u , xa});
                    op.push_back({xa , xa});
                    swap(a[u] , a[xa]);
                }
            }
        }
    }
    cout << ans << ' ' << op.size() << endl;
    for (auto [x, y] : op)
        cout << x << ' ' << y << endl;
}
int main()
{
    read_fast;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}