#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long x, y;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;
    
    long long count0 = 0, count1 = 0;
    vector<int> pos; // 记录错误位的位置，用于判断 m==2相邻情况
    for (int i = 0; i < n; i++){
        int da = a[i] - '0';
        int db = b[i] - '0';
        int dc = c[i] - '0';
        int d = da ^ db;
        if(d != dc){
            pos.push_back(i);
            if(da == 0) count0++;
            else count1++;
        }
    }
    
    long long tot = count0 + count1;
    long long candidate1 = tot * x; // 全部翻转
    
    long long candidate2 = 0;
    if(tot == 2 && pos.size() == 2 && pos[1] == pos[0] + 1){
        candidate2 = min(y, 2*x);
    } else {
        candidate2 = min(count0, count1) * y + (max(count0, count1) - min(count0, count1)) * x;
    }
    
    long long ans = min(candidate1, candidate2);
    cout << ans << "\n";
    return 0;
}