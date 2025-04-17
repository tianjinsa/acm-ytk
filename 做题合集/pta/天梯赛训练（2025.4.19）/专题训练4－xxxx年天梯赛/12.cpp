#include<bits/stdc++.h>
using namespace std;
vector<vector<char>>mp;
int all=0,ha=0;
stack<pair<int,int>>st;
int ss(int x,int y){
    int fl=0;
    st.push({x,y});
    while(!st.empty()){
        auto [currX,currY]=st.top();
        st.pop();
        if(mp[currX][currY]!='0'){
            if(mp[currX][currY]!='1'){
                fl=1;
            }
            mp[currX][currY]='0';
            if(currX>0)
                st.push({currX-1,currY});
            if(currX<mp.size()-1)
                st.push({currX+1,currY});
            if(currY>0)
                st.push({currX,currY-1});
            if(currY<mp[0].size()-1)
                st.push({currX,currY+1});
        }
    }
    return fl;
}
int main()
{
    int x,y;
    cin>>x>>y;
    mp.resize(x,vector<char>(y));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            cin>>mp[i][j];
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(mp[i][j]!='0'){
                ha+=ss(i,j);
                all++;
            }
        }
    }
    cout<<all<<' '<<ha<<endl;

    return 0;
}