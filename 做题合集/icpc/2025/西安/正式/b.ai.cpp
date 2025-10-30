#include<bits/stdc++.h>
using namespace std;

string build(int len, map<char,int> cnt, char p, char nxt, const string& ord){
    string res="";
    char last=p;
    for(int i=0; i<len; ++i){
        char best=0;
        for(char c:ord){
            if(cnt[c]>0 && c!=last){
                cnt[c]--;
                int rem=len-1-i;
                int mx=0;
                if(rem>0){
                    for(auto&[k,v]:cnt)mx=max(mx,v);
                }
                if(2*mx<=rem+1){
                    if(rem>0 || c!=nxt){
                        best=c;
                        break;
                    }
                }
                cnt[c]++;
            }
        }
        if(best==0)return"";
        res+=best;
        last=best;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool good=1;
    for(int i=0; i<n-1; ++i){
        if(s[i]==s[i+1]){
            good=0;
            break;
        }
    }
    if(good){
        cout<<"Beautiful\n";
        return;
    }
    int lb=-1,rb=-1;
    for(int i=0; i<n-1; ++i){
        if(s[i]==s[i+1]){
            if(lb==-1)lb=i;
            rb=i;
        }
    }
    int l0=lb+1;
    int r0=rb+2;
    queue<pair<int,int>> q;
    q.push({l0,r0});
    set<pair<int,int>> vis;
    vis.insert({l0,r0});
    while(!q.empty()){
        auto[l,r]=q.front();
        q.pop();
        map<char,int> cnt;
        for(int i=l-1; i<r; ++i)cnt[s[i]]++;
        char p=(l>1)?s[l-2]:0;
        char nxt=(r<n)?s[r]:0;
        string ord="CPW";
        sort(ord.begin(),ord.end());
        do{
            string sub=build(r-l+1,cnt,p,nxt,ord);
            if(!sub.empty()){
                cout<<"Possible\n";
                cout<<l<<" "<<r<<"\n";
                cout<<s.substr(0,l-1)<<sub<<s.substr(r)<<"\n";
                return;
            }
        }while(next_permutation(ord.begin(),ord.end()));
        if(l>1 && vis.find({l-1,r})==vis.end()){
            q.push({l-1,r});
            vis.insert({l-1,r});
        }
        if(r<n && vis.find({l,r+1})==vis.end()){
            q.push({l,r+1});
            vis.insert({l,r+1});
        }
    }
    cout<<"Impossible\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
