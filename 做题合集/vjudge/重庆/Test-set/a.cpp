#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin>>Q;
    unordered_map<string,int> mp;
    while(Q--){
        int op;
        cin>>op;
        if(op == 1){
            string name;
            int s;
            cin>>name>>s;
            mp[name]=s;
            cout<<"OK\n";
        }
        else if(op==2){
            string name;
            cin>>name;
            auto it=mp.find(name);
            if(it!=mp.end())
                cout<<it->second<<"\n";
            else
                cout<<"Not found\n";
        }
        else if(op == 3){
            string name;
            cin>>name;
            auto it=mp.find(name);
            if(it!=mp.end()){
                mp.erase(it);
                cout<<"Deleted successfully\n";
            }else{
                cout<<"Not found\n";
            }
        }
        else if(op==4){
            cout<<mp.size()<<"\n";
        }
    }
    return 0;
}