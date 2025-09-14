#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string e,s;
    cin>>e>>s;
    if(e.length()!=s.length()){
        cout<<"NO\n";
        return 0;
    }

    vector<int> s1(26,0),s2(26,0);
    for(char c : e){
        s1[c-'A']++;
    }

    for(char c : s){
        s2[c-'A']++;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1 == s2){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }

    return 0;
}
