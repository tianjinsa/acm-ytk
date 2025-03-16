#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>toys;
vector<int>best;
bool found=0;
bool check(const vector<int>& st){
    for(int i=0;i<n;i++){
        if(st[i]!=1) return 0;
    }
    return 1;
}
void dfs(vector<int>& cur,vector<int>& st,vector<bool>& used){
    if(found&&cur.size()>=best.size())return;
    if(check(st)){
        if(!found||cur.size()<best.size()){
            best=cur;
            found=1;
        }
        return;
    }

    for(int i=1;i <= m;i++){
        if(used[i]) continue;
        vector<int>pre=st;
        
        for(int j=0;j<n;j++){
            if(toys[i-1][j] == 1){
                st[j]=1;
            } else if(toys[i-1][j] == -1){
                st[j]=-1;
            }
        }
        cur.push_back(i);
        used[i]=1;
        dfs(cur,st,used);
        used[i]=0;
        cur.pop_back();
        st=pre;
    }
}

int main(){
    cin>>n>>m;
    toys.resize(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>toys[i][j];
        }
    }
    vector<int>cur;
    vector<int>st(n,-1);
    vector<bool>used(m+1,0);
    dfs(cur,st,used);
    for(int i=0;i<best.size();i++){
        cout<<best[i];
        if(i<best.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}