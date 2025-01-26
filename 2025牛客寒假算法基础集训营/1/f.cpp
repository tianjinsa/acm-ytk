#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    scanf("%d",&m);
    while(m--){
        int n,t;
        scanf("%d",&n);
        int a[n];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int ans = 0;
        for(int i = 2; i <= n; i += 2){
            unordered_map<int,int> freq;
            // 初始化前 i 个元素的频率
            for(int j = 0; j < i; j++){
                freq[a[j]]++;
            }
            // 检查是否双生
            if(freq.size() == 2){
                auto it = freq.begin();
                auto it2 = next(it);
                if(it->second == it2->second) ans++;
            }
            // 滑动窗口
            for(int j = i; j < n; j++){
                freq[a[j - i]]--;
                if(freq[a[j - i]] == 0) freq.erase(a[j - i]);
                freq[a[j]]++;
                if(freq.size() == 2){
                    auto it = freq.begin();
                    auto it2 = next(it);
                    if(it->second == it2->second) ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}