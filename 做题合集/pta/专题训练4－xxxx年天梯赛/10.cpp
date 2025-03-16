#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int ss(string &s){
    for(auto &c:s){
        c=tolower(c);
    }
    string t="chatgpt";
    int p=0,sum=0;
    while((p=s.find(t,p))!=-1){
        sum++;
        p+=t.size();
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        string u;
        cin>>u;
        cin.ignore(1,'\n');
        string s;
        getline(cin,s);
        mp[u]+=ss(s);
    }
    vector<pair<string,int>>ans(mp.begin(),mp.end());
    sort(ans.begin(),ans.end(),[](pair<string,int> &a,pair<string,int>& b) {
        if(a.second==b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    for(int i=0;i<3&&i<ans.size();i++){
        if(ans[i].second>0)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}