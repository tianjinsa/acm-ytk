#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    if(!(cin>>N)) return 0;
    unordered_map<string,set<int>> mp;
    string word;
    for(int i=1;i<=N;++i) {
        int L;
        cin>>L;
        while(L--) {
            cin>>word;
            mp[word].insert(i);
        }
    }
    int M;
    cin>>M;
    while(M--) {
        cin>>word;
        if(mp.count(word)) {
            auto &v = mp[word];
            bool fl=0;
            for(auto it = v.begin(); it != v.end(); ++it) {
                if(fl) cout<<" ";
                else fl=1;
                cout<<*it;
            }
        }
        cout<<"\n";
    }
    return 0;
}