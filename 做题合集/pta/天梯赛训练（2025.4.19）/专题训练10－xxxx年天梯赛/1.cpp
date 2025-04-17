#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum=0;
    cin>>n;
    
    vector<int> teams(n),t2(n);
    list<int> t;
    vector<vector<int>> out(n,vector<int>(0));
    for(int i=0;i<n;i++){
        cin>>teams[i];
        t2[i]=teams[i];
        teams[i]*=10;
        sum+=teams[i];
    }
    for(int i=1;;){
        int aa=0;
        for(int t=0;t<n;t++){
            if(teams[t]>0){
                aa++;
                if(!out[t].empty()&&out[t].back()==i-1)i++;
                out[t].push_back(i);
                teams[t]--;
                i++;
            }
        }
        if(aa==0)break;
    }
    for(int i=1;i<=n;i++){
        cout<<"#"<<i<<endl;
        for(int j=0;j<t2[i-1];j++){
            for(int k=0;k<9;k++){
                cout<<out[i-1][k+j*10]<<" ";
            }
            cout<<out[i-1][j*10+9]<<endl;
        }
    }
    return 0;
}