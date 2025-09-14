#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n)
    {
        int st=0;
        vector<int>f(n);
        for(int i=0;i<n;i++){
            cin>>f[i];
            f[i]--;
        }
        vector<int> t;
        vector<bool>vis(n);
        vector<vector<int>> cycles;
        for(int i=0;i<n;i++){
            int now=i,len=1;
            if(vis[now])continue;
            while(!vis[now])
            {
                t.push_back(now);
                vis[now]=1;
                now=f[now];
                len++;
            }
            cycles.push_back(t);
            st++;
            t.clear();
        }
        
        int x;
        while(cin>>x&&x){
            string s;
            getline(cin,s);
            s.erase(0,1);
            s+=string(n-s.size(),' ');
            string tt(n,' ');
            for(auto &cycle: cycles){
                int len=cycle.size();
                int shift=x % len;
                for(int j=0;j<len;j++){
                    int from=cycle[j];
                    int to=cycle[(j+shift)%len];
                    tt[to]=s[from];
                }
            }
            cout<<tt<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}