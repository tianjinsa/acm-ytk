#include<bits/stdc++.h>
using namespace std;

long long n,a,b;
vector<long long> ans;

void dfs(int pos,long long xxx) {
    if (pos > n) {
        if (xxx >= a && xxx <= b) ans.push_back(xxx);
        return;
    }
    for (int d=(pos==1 ? 1 : 0);d <= 9;++d) {
        long long nxt=xxx * 10 + d;
        if (nxt % pos==0) dfs(pos + 1,nxt);
    }
}

int main() {
    if (!(cin >> n >> a >> b)) return 0;
    dfs(1,0);
    if (ans.empty()) {
        cout << "No Solution";
    } else {
        for (auto x : ans) cout << x << '\n';
    }
    return 0;
}