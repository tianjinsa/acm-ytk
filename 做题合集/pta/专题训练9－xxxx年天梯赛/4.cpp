#include<bits/stdc++.h>
using namespace std;
map<string,int>mp={{"ChuiZi",0},{"JianDao",1},{"Bu",2}};
string s[3]={"ChuiZi","JianDao","Bu"};
int main()
{
    int k,k2;
    cin>>k;
    string a;
    k2=k;
    while(cin>>a){
        if(a=="End")break;
        if(k2!=0){
            cout<<s[(mp[a]-1+3)%3]<<endl;
            k2--;
        }
        else{
            cout<<a<<endl;
            k2=k;
        }
    }
    return 0;
}