#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>>mp;
double yy(int x1,int y1,int x2,int y2,int dx){
    return 1.0*(y1-y2)/(x1-x2)*(dx-x1)+y1;
}
bool check(int x1,int y1,int x2,int y2){

    for(auto [x, y] : mp){
        double dy=yy(x1,y1,x2,y2,x);
        if(abs(dy - y[0]) < 1e-9 || abs(dy < y[1])< 1e-9){
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        mp[a]={b,c};
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        for(int a=0;a<2;a++){
            for(auto j=next(i);j!=mp.end();j++){
                for(int b=0;b<2;b++){
                    if(check(i->first,i->second[a],j->first,j->second[b])){
                        cout<<i->first<<" "<<i->second[a]<<" "<<j->first<<" "<<j->second[b]<<endl;
                        return 0;
                    }
                }
            }
        }
        
    }
    return 0;
}