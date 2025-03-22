#include<bits/stdc++.h>
using namespace std;

int lcp(const string &a, const string &b) {
    int len = min(a.size(), b.size()), i = 0;
    while (i < len && a[i] == b[i]) i++;
    return i;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; 
    cin >> n >> m; 
    vector<string> words(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    while(m--){
        int l, r;
        cin >> l >> r;
        vector<string> subset(words.begin() + (l - 1), words.begin() + r);
        long long ans = subset[0].size();
        for(int i = 0; i < (int)subset.size() - 1; i++){
            int common = lcp(subset[i], subset[i+1]);
            ans += (subset[i+1].size() + subset[i].size() - 2LL * common);
        }
        cout << ans << "\n";
    }
    return 0;
}