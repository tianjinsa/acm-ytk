#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>>mp;
bool check(vector<int>aim){
    for (int i = 1; i <= aim.size(); i++) {
        for (int next : mp[i]) {
            if (aim[i - 1] == aim[next - 1])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int v,e,k;
    cin>>v>>e>>k;
    while(e--){
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    cin>>e;
    while(e--){
        vector<int>aim(v,0);
        set<int>st;
        for(int i=0;i<v;i++){
            int a;
            cin>>a;
            aim[i]=a;
            st.insert(a);
        }
        if(st.size()!=k||check(aim)==0){
            cout<<"No"<<endl;
        }
        else{
            cout << "Yes" << endl;
        }

    }
    return 0;
}