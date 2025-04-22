#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    const int OFFSET = 1000000;
    vector<char> f0(2*OFFSET+1), f1(2*OFFSET+1), f2(2*OFFSET+1);
    vector<int> v0, v1, v2;
    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        if(y == 0) {
            if(!f0[x+OFFSET]) { f0[x+OFFSET] = 1; v0.push_back(x); }
        } else if(y == 1) {
            if(!f1[x+OFFSET]) { f1[x+OFFSET] = 1; v1.push_back(x); }
        } else {
            if(!f2[x+OFFSET]) { f2[x+OFFSET] = 1; v2.push_back(x); }
        }
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<tuple<int,int,int>> res;
    long long xpmclzjkln;
    bool small0 = v0.size() < v2.size();
    for(int xi : v1) {
        if(small0) {
            for(int x0 : v0) {
                xpmclzjkln = 2LL*xi - x0;
                if(xpmclzjkln >= -OFFSET && xpmclzjkln <= OFFSET && f2[(int)xpmclzjkln+OFFSET]) {
                    res.emplace_back(x0, xi, (int)xpmclzjkln);
                }
            }
        } else {
            for(int x2 : v2) {
                xpmclzjkln = 2LL*xi - x2;
                if(xpmclzjkln >= -OFFSET && xpmclzjkln <= OFFSET && f0[(int)xpmclzjkln+OFFSET]) {
                    res.emplace_back((int)xpmclzjkln, xi, x2);
                }
            }
        }
    }
    if(res.empty()) {
        cout << -1;
        return 0;
    }
    sort(res.begin(), res.end(), [](auto &a, auto &b) {
        if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<0>(a) < get<0>(b);
    });
    for(auto &t : res) {
        cout << "[" << get<0>(t) << ", 0] [" << get<1>(t) << ", 1] [" << get<2>(t) << ", 2]\n";
    }
    return 0;
}