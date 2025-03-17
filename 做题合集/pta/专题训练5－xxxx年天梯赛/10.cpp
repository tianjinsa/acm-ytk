#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    vector<int>em;
    vector<pair<int,string>>sch(n);
    for(int i=0;i<n;i++){
        cin>>sch[i].second>>sch[i].first;
    }
    set<pair<int,string>>st(sch.begin(),sch.end());
    while(!st.empty()) {
        auto [nn,na]=*prev(st.end());
        st.erase(prev(st.end()));
        if(nn>c){
            nn-=c;
            st.insert({nn,na});
            em.push_back(c);
        }
        else if(nn==c){
            em.push_back(c);
        }
        else{
            bool fl=1;
            for(auto it=em.begin();it!=em.end();++it){
                if(nn<=(c-*it)){
                    *it+=nn;
                    fl=0;
                    break;
                }
            }
            if(fl){
                em.push_back(nn);
            }
        }
    }
    for(auto&[b,a]:sch){
        cout<<a<<' '<<(b-1)/c+1<<endl;
    }
    cout<<em.size()<<endl;
    return 0;
}