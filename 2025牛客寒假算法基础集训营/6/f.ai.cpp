#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<pair<long long, long long>> offers(n);
        for(int i = 0; i < n; i++){
            cin >> offers[i].first >> offers[i].second;
        }
        sort(offers.begin(), offers.end(), [](auto &x, auto &y){
            return x.first < y.first;
        });
        // 初始薪水，选择所有offer中最大的a
        long long curr = offers.back().first;
        int idx = 0;
        while(idx < n){
            long long newCurr = curr;
            while(idx < n && offers[idx].first <= curr){
                newCurr = max(newCurr, offers[idx].first + offers[idx].second);
                idx++;
            }
            if(newCurr == curr) break;
            curr = newCurr;
        }
        cout << curr << "\n";
    }
    return 0;
}
