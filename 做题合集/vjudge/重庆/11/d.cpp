#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;cin >> N;
        vector<pair<long long,long long>> v(N);
        for(int i=0;i<N;i++){
            cin >> v[i].second;
            v[i].first=llabs(v[i].second);
        }
        sort(v.begin(),v.end());
        bool fl=true;
        if(N>=3){
            for(int i=2;i<N;i++){
                if((__int128)v[i].second*v[0].second != (__int128)v[i-1].second*v[1].second){
                    fl=false;
                    break;
                }
            }
        }
        if(v[0].first==v[N-1].first){
            unordered_map<long long,long long> mp;
            for(int i=0;i<N;i++){
                mp[v[i].second]++;
            }
            if(mp.size()>2){
                fl=0;
            }
            else if(mp.size()==1){
                fl=1;
            }
            else{
                int cnt=mp.begin()->second;
                if((N%2&&abs(cnt*2-N)==1)||(N%2==0&&cnt*2==N)){
                    fl=1;
                }
                else{
                    fl=0;
                }
            }
        }
        cout<<(fl?"Yes":"No")<<"\n";
    }
    return 0;
}