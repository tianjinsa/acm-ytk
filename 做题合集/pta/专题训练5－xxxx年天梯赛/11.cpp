#include<bits/stdc++.h>
using namespace std;
vector<int>num;
set<int>st;
int up=0;
void inn(int &x){
    if(up >= st.size()) {
        cout << "No Solution" << endl;
        exit(0);
    }
    auto it=next(st.begin(),up);
    int p=*it-1;
    st.erase(it);
    num[p]=x;
    up++;
}
int main()
{
    int k;
    cin>>k;
    num.resize(1<<k);
    iota(num.begin(),num.end(),1);
    st.insert(num.begin(),num.end());
    for(int i=k;i>=1;i--){
        for(int j=0;j<(1<<(i-1));j++){
            int x;
            cin>>x;
            inn(x);
        }
        up=0;
    }
    int t;
    cin>>t;
    inn(t);
    bool fl=0;
    for(auto& x:num){
        if(fl)cout<<' ';
        fl=1;
        cout<<x;
    }
    return 0;
}