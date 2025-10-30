#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d,k;
    cin>>d>>k;
    vector<string> p(k);
    for(int i=0;i<k;++i){
        cin>>p[i];
    }
    sort(p.begin(),p.end());
    unordered_set<string> seen;
    long long ans=0;
    do{
        string s="";
        for(const auto&x:p){
            s+=x;
        }
        if(s.size()>1 && s[0]=='0') continue;
        // cout<<s<<endl;
        long long rem=0;
        for(char &c:s){
            rem=(rem*10+(c-'0'))%d;
        }
        if(rem==0){
            string t=s;
            auto pos=t.find_first_not_of('0');
            if(pos==-1) t="0";
            else t=t.substr(pos);
            if(seen.insert(t).second) ans++;
        }
    }while(next_permutation(p.begin(),p.end()));
    cout<<ans;
    return 0;
}
