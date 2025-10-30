#include <bits/stdc++.h>
using namespace std;
map<set<int>, int> mp;
vector<set<int>> sets;
int getId(const set<int>& s){
    auto it=mp.find(s);
    if (it!=mp.end()) return it->second;
    int id=sets.size();
    sets.push_back(s);
    mp[s]=id;
    return id;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while (T--){
        int n;
        cin>>n;
        mp.clear();
        sets.clear();
        getId(set<int>());
        stack<int> st;
        while (n--){
            string op;
            cin>>op;
            if (op=="PUSH"){
                st.push(getId(set<int>()));
            } else if (op=="DUP"){
                st.push(st.top());
            } else if (op=="UNION"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                set<int> s=sets[a];
                s.insert(sets[b].begin(), sets[b].end());
                st.push(getId(s));
            } else if (op=="INTERSECT"){
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                set<int> s;
                for (int x : sets[a]) if (sets[b].count(x)) s.insert(x);
                st.push(getId(s));
            } else{
                int a=st.top(); st.pop();
                int b=st.top(); st.pop();
                set<int> s=sets[b];
                s.insert(a);
                st.push(getId(s));
            }
            cout<<sets[st.top()].size()<<"\n";
        }
        cout<<"***\n";
    }
    return 0;
}