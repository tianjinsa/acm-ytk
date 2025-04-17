#include<bits/stdc++.h>
using namespace std;

int main()
{
    int out[]={10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
    set<int> st={1,2,3,4,5,6,7,8,9};
    int tx,ty,mp[3][3];
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cin>>mp[i][j];
            st.erase(mp[i][j]);
            if(mp[i][j]==0){
                tx=i;
                ty=j;
            }
        }
    }
    mp[tx][ty]=*st.begin();
    for(int i=0;i<3;++i){
        int x,y;
        cin>>x>>y;
        cout<<mp[x-1][y-1]<<endl;
    }
    int ans,sum=0;
    cin>>ans;
    if(ans==1){
        sum=mp[0][0]+mp[0][1]+mp[0][2];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==2){
        sum=mp[1][0]+mp[1][1]+mp[1][2];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==3){
        sum=mp[2][0]+mp[2][1]+mp[2][2];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==4){
        sum=mp[0][0]+mp[1][0]+mp[2][0];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==5){
        sum=mp[0][1]+mp[1][1]+mp[2][1];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==6){
        sum=mp[0][2]+mp[1][2]+mp[2][2];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==7){
        sum=mp[0][0]+mp[1][1]+mp[2][2];
        cout<<out[sum-6]<<endl;
    }
    else if(ans==8){
        sum=mp[0][2]+mp[1][1]+mp[2][0];
        cout<<out[sum-6]<<endl;
    }
    return 0;
}