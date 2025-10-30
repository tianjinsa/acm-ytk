#include<bits/stdc++.h>
using namespace std;
struct node
{
    char c;
    int cnt;
    node(int c){
        this->c=c;
        cnt=0;
    }
};
vector<long long>C,W,P;
        string s;
int n;
inline long long ssum(const vector<long long>&arr,const int l,const int r){
    return arr[r+1]-arr[l];
}
inline long long get(char c ,int l,int r){
    if(c=='C')return ssum(C,l,r);
    else if(c=='W')return ssum(W,l,r);
    else return ssum(P,l,r);
}
inline bool check(int l,int r){
    vector<pair<int,char>>tmp(3);
    tmp[0]={ssum(C,l,r),'C'};
    tmp[1]={ssum(W,l,r),'W'};
    tmp[2]={ssum(P,l,r),'P'};
    sort(tmp.begin(),tmp.end());
    if(tmp[0].first==0&&tmp[1].first&&tmp[1].first+1>=tmp[2].first&&(l-1>=0&&tmp[2].second!=s[l-1])&&(r+1<n&&tmp[0].second!=s[r+1]))return 1;
    if(tmp[2].first>tmp[1].first+tmp[0].first)return 0;
    return 1;
}
int find_l(int l,int xl,int xr){
    int x=max(0,xr-l+1);
    for(int i=xl;i>=x;i--){
        if(check(i,i+l-1))return i;
    }
    return -1;
}
pair<int,int> find_ll(int xl,int xr){
    int nl=max(2,xr-xl+1), nr=n,mid;
    mid=nl;
    int begin,t;
    while(nl<nr){
        // cout<<"Debug: "<<nl<<" "<<nr<<" "<<mid<<" !2\n";
        if((t=find_l(mid,xl,xr))!=-1){
            nr=mid;
        }
        else{
            nl=mid+1;
        }
        if(t!=-1)begin=t;
        mid=(nl+nr)/2;
    }
    // cout<<"Debug: "<<nl<<" "<<begin<<" !3\n";
    return {nr,begin};
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n>>s;
        C.assign(n+1,0);
        W.assign(n+1,0);
        P.assign(n+1,0);
        int l=-1,r=-1;
        for(int i=0;i<n;i++){
            C[i+1]=C[i];
            W[i+1]=W[i];
            P[i+1]=P[i];
            if(s[i]=='C')C[i+1]+=1;
            else if(s[i]=='W')W[i+1]+=1;
            else P[i+1]+=1;
            if(i&&s[i]==s[i-1]){
                if(l==-1)l=i;
                r=i-1;
                // cout<<"Debug: "<<l<<" "<<r<<" !1\n";
            }
        }
        if(l>r)r=l;
        if(l==-1){
            cout<<"Beautiful"<<'\n';
            continue;
        }
        if(!check(0,l-1)){
            cout<<"Impossible"<<'\n';
            continue;
        }
        auto [len,begin]=find_ll(l,r);//长度为nl，左端点为xl
        // cout<<s.substr(0,len);
        if(len==3){
            cout<<"Possible"<<'\n';
            string res="000",tem="CPW";
            for(char &j:tem){
                if(get(j,begin,begin+len-1)==1){
                    res[1]=j;
                    
                }
                if(get(j,begin,begin+len-1)==2){
                    res[0]=res[2]=j;
                }
            }
            int dx=0,dy=0;
            for(int i=0;i<res.size()/2;i++){
                int fl=2;
                if(s[begin+i]==res[i]){
                    swap(res[i],res[dx]);
                    dx++;
                }
                else fl--;
                if(s[begin+len-1-i]==res[res.size()-1-i]){
                    dy++;
                }
                else fl--;
                if(!fl)break;
            }
            cout<<begin+1+dx<<" "<<begin+len-dy<<'\n';

            cout<<s.substr(0,begin)<<res<<s.substr(begin+len)<<'\n';
            continue;
        }
        char lx=-1,rx=-1;
        if(begin-1>=0)lx=s[begin-1];
        if(begin+len<n)rx=s[begin+len];
        string t1(1, s[begin]), t2(1, s[begin+len-1]);
        string tem[3]={t1+"CPW",t2+"CPW","CPW"},ans="000";
        // cout<<"Debug: 0:"<<tem[0]<<" 1:"<<tem[1]<<" 2:"<<tem[2]<<'\n';
        for(char &i:tem[0]){
            // cout<<"Debug: i="<<i<<'\n';
            if(i==lx)continue;
            // cout<<"Debug: i="<<i<<'\n';
            for(char &j:tem[1]){
                if(j==rx||j==i)continue;
                // cout<<"Debug: j="<<j<<'\n';
                for(char &k:tem[2]){
                    if(k==i||k==j/* ||get(k,begin,begin+len-1)==get(i,begin,begin+len-1)+get(j,begin,begin+len-1) */)continue;
                    
                    ans[0]=i;
                    ans[1]=k;
                    ans[2]=j;
                    // cout<<"Debug: "<<ans<<' '<<begin<<' '<<len<<'\n';
                    goto to;
                }
            }
        }
        to:
        string out[3]={""};

        // cout<<"Debug: "<<ans<<' '<<begin<<' '<<len<<'\n';

        long long outn[3]={0},inn[3]={get(ans[0],begin,begin+len-1),get(ans[1],begin,begin+len-1),get(ans[2],begin,begin+len-1)};
        out[1]=ans;
        // out[0]={ans[0],ans[1]};
        // out[2]={ans[1],ans[2]};

        if(inn[0]>=inn[1]&&inn[0]>=inn[2]){
            outn[1]=abs(inn[1]+inn[2]-inn[0]);
            outn[2]=inn[2]-outn[1];
            out[2]={ans[0],ans[2]};
            outn[0]=inn[1]-outn[1];
            out[0]={ans[0],ans[1]};
        }
        else if(inn[1]>=inn[0]&&inn[1]>=inn[2]){
            outn[1]=abs(inn[0]+inn[2]-inn[1]);
            
            outn[2]=inn[2]-outn[1];
            out[2]={ans[1],ans[2]};
            outn[0]=inn[0]-outn[1];
            out[0]={ans[0],ans[1]};
        }
        else{
            outn[1]=abs(inn[0]+inn[1]-inn[2]);
            outn[2]=inn[1]-outn[1];
            out[2]={ans[0],ans[2]};
            out[0]={ans[1],ans[2]};
            outn[0]=inn[0]-outn[1];
        }
        string res;

        cout<<"Possible"<<'\n';
        cout<<"Debug: ";
        cout<<begin+1<<" "<<begin+len<<'\n';
        cout<<inn[0]<<" "<<inn[1]<<" "<<inn[2]<<'\n';
        cout<<outn[0]<<" "<<outn[1]<<" "<<outn[2]<<'\n';
        cout<<ans<<'\n';
        cout<<out[0]<<" "<<out[1]<<" "<<out[2]<<'\n';

        while(outn[0]-->0)res+=out[0];
        while(outn[1]-->0)res+=out[1];
        while(outn[2]-->0)res+=out[2];
        int dx=0,dy=0;
        for(int i=0;i<res.size()/2;i++){
            int fl=2;
            if(s[begin+i]==res[i]){
                dx++;
            }
            else fl--;
            if(s[begin+len-1-i]==res[res.size()-1-i]){
                dy++;
            }
            else fl--;
            if(!fl)break;
        }
        cout<<begin+1+dx<<" "<<begin+len-dy<<'\n';

        cout<<s.substr(0,begin)<<res<<s.substr(begin+len)<<'\n';
        

    }
    return 0;
}