#include<bits/stdc++.h>
using namespace std;
map<string,set<string>>mp;
string ss(string a){
    string out;
    int t=0;
    while((t=a.find_first_not_of(' ',t))!=-1) {
        out+=a[t];
        t=a.find(' ',t);
    }
    return out;
}
int main()
{
    int n;
    cin>>n;
    cin.ignore(1,'\n');
    while(n--){
        string tt;
        getline(cin,tt);
        mp[ss(tt)].insert(tt);
    }
    cin>>n;
    cin.ignore(1,'\n');
    while(n--){
        string tt,c;
        getline(cin,tt);
        if(mp.find(ss(tt))==mp.end()){
            cout<<tt<<endl;
            continue;
        }
        c=ss(tt);
        for(auto& t:mp[c]) {
            if(t==*mp[c].begin())
                cout<<t;
            else
                cout<<"|"<<t;
        }
        cout << endl;
    }
    return 0;
}