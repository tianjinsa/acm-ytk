#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    string str[n];
    cin.ignore(1,'\n');
    for(int i=0;i<n;i++){
        getline(cin,str[i]);
    }
    map<int,int>mp;
    int b[m][10];
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        mp[t]=i;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<10;j++){
            cin>>b[i][j];
        }
    }
    cin>>n;
    while(n--){
        int x,y;
        cin>>x;
        y=x%10;
        x/=10;
        if(mp.find(x)==mp.end()||b[mp[x]][y]==-1){
            cout<<'?'<<endl;
        }
        else{
            cout<<str[b[mp[x]][y]-1]<<endl;
        }
        
    }
    return 0;
}