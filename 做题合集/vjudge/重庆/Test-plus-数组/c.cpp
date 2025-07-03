#include<bits/stdc++.h>
using namespace std;

vector<string> rot90(const vector<string>& m) {
    int n = m.size();
    vector<string> t(n, string(n, ' '));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            t[j][n-1-i] = m[i][j];
    return t;
}

vector<string> reflect(const vector<string>& m) {
    vector<string> t = m;
    for(auto &s : t) reverse(s.begin(), s.end());
    return t;
}

int main()
{
    int n;
    cin>>n;
    vector<string> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    if(rot90(a)==b){
        cout<<1;
        return 0;
    }
    if(rot90(rot90(a))==b){
        cout<<2;
        return 0;
    }
    if(rot90(rot90(rot90(a)))==b){
        cout<<3;
        return 0;
    }
    if(reflect(a)==b){
        cout<<4;
        return 0;
    }
    auto r=reflect(a);
    if(rot90(r)==b || rot90(rot90(r))==b || rot90(rot90(rot90(r)))==b){
        cout<<5;
        return 0;
    }
    if(a==b){
        cout<<6;
        return 0;
    }
    cout<<7;
    return 0;
}