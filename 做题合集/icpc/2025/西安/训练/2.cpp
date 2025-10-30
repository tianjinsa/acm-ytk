#include<bits/stdc++.h>
using namespace std;
long long MOD=1LL<<31;
long long gid(long long x,long long y){
    return x+y*MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long T;
    cin>>T;
    while(T--){
        long long n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        cout.flush();
        long long x=0,y=0;
        unordered_set<long long>st;
        for(auto&c:s){
            if(c=='D')y--;
            else if(c=='U')y++;
            else if(c=='L')x--;
            else x++;
        }
        long long ans=0,p=y,q=x;
        long long M=__gcd(abs(p),abs(q));
        if(M!=0){
            p/=M;
            q/=M;
        }
        if(x==0&&y==0){
            x=0,y=0;
            for(auto&c:s){
                st.insert(gid(x,y));
                if(c=='D')y--;
                else if(c=='U')y++;
                else if(c=='L')x--;
                else x++;
            }
            for(int i=0;i<m;i++){
                cin>>x>>y;
                if(st.count(gid(x,y))){
                    ans++;
                }
            }

        }
        else{
            x=0,y=0;
            for(auto&c:s){
                st.insert(q*y-p*x);
                if(c=='D')y--;
                else if(c=='U')y++;
                else if(c=='L')x--;
                else x++;
            }
            for(int i=0;i<m;i++){
                cin>>x>>y;
                if(st.count(q*y-p*x)){
                    ans++;
                }
            }
        
        }
        
        
        cout<<ans<<'\n';
    }
    return 0;
}