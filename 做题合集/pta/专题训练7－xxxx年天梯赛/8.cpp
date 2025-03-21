#include<bits/stdc++.h>
using namespace std;
vector<int> k;
map<string,int> m={{"ChuiZi",0},{"JianDao",1},{"Bu",2}};
vector<string>ss={"ChuiZi","JianDao","Bu"};
int main()
{
    int win=0,ki=0;
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        k.push_back(t);
    }
    string in;
    
    while(cin>>in&&in!="End"){
        int fl=1;
        if(win<k[ki]){
            fl=-1;
            win++;
        }
        else{
            ki++;
            win=0;
            if(ki>=k.size())ki=0;
        }
        int out=m[in]+fl;
        out=(out+3)%3;
        cout<<ss[out]<<endl;
    }
    return 0;
}