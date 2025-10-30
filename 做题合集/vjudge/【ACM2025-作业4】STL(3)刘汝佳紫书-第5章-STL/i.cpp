#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        cin.ignore();
        vector<vector<string>> table(n,vector<string>(m));
        string rs;
        for(int i=0;i<n;i++){
            getline(cin,rs);
            stringstream ss(rs);
            vector<string> row;
            for(int i=0;i<m;i++){
                string s;
                getline(ss,s,(i==m-1?'\n':','));
                row.push_back(s);
            }
            table[i]=row;
        }
        bool ok=true;
        int fr1,fr2,fc1,fc2;
        for(int c1=0;c1<m && ok;c1++){
            for(int c2=c1+1;c2<m;c2++){
                map<string,int> mp;
                for(int i=0;i<n;i++){
                    string key=table[i][c1]+","+table[i][c2];
                    if(mp.count(key)){
                        ok=false;
                        fr1=mp[key];
                        fr2=i;
                        fc1=c1;
                        fc2=c2;
                        break;
                    }
                    else mp[key]=i;
                }
                if(!ok) break;
            }
        }
        if(ok) cout<<"YES\n";
        else{
            cout<<"NO\n"<<fr1+1<<" "<<fr2+1<<"\n"<<fc1+1<<" "<<fc2+1<<"\n";
        }
    }

    return 0;
}