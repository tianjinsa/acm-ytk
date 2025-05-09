#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(){
    int n;
    if(!(cin>>n))return 0;
    vector<pair<double,double>> pts(n);
    for(int i=0;i<n;i++) cin>>pts[i].first>>pts[i].second;
    vector<double> angs;
    angs.reserve(2*n*(n-1)/2 + 1);
    angs.push_back(0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dx = pts[j].first - pts[i].first;
            double dy = pts[j].second - pts[i].second;
            double a1 = atan2(dy, -dx);
            double a2 = atan2(dy, dx);
            if(a1<0) a1 += 2*PI;
            if(a2<0) a2 += 2*PI;
            angs.push_back(a1);
            angs.push_back(a2);
        }
    }
    sort(angs.begin(), angs.end());
    angs.erase(unique(angs.begin(), angs.end()), angs.end());
    int m = angs.size();
    int ans = 1;
    for(int k=0;k<m;k++){
        double t1 = angs[k];
        double t2 = (k+1<m? angs[k+1] : angs[0] + 2*PI);
        double theta = (t1 + t2) / 2;
        if(theta >= 2*PI) theta -= 2*PI;
        double c = cos(theta), s = sin(theta);
        vector<pair<double,double>> rp;
        for(auto &p: pts){
            double x = p.first * c - p.second * s;
            double y = p.first * s + p.second * c;
            if(x >= -1e-9 && y >= -1e-9) rp.emplace_back(x,y);
        }
        sort(rp.begin(), rp.end(), [](auto &a, auto &b){
            if(fabs(a.first - b.first)>1e-9) return a.first < b.first;
            return a.second < b.second;
        });
        int sz = rp.size();
        vector<int> dp(sz,1);
        for(int i=0;i<sz;i++){
            for(int j=0;j<i;j++){
                if(rp[j].second <= rp[i].second + 1e-9)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
    }
    cout<<ans;
    return 0;
}