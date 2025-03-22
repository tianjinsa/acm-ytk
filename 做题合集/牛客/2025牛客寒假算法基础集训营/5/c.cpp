#include <bits/stdc++.h>
using namespace std;
 
int main(){
    
    int n;
    long long x, y;
    cin >> n >> x >> y;
    string a, b, c;
    cin >> a >> b >> c;
    
    int cnt[2]={0};
    for(int i = 0; i < n; i++){
        int da = a[i]-'0';
        int db = b[i]-'0';
        int dc = c[i]-'0';
        int d = da ^ db;
        if(d != dc){
            cnt[da]++;
        }
    }
    
    long long ans = 0;

    if(2*x<=y){
        ans = cnt[1]*x + cnt[0]*x;
    }else{
        ans = min(cnt[0], cnt[1])*y + (max(cnt[0], cnt[1])-min(cnt[0], cnt[1]))*x;
    }
    
    cout << ans << "\n";
    return 0;
}
