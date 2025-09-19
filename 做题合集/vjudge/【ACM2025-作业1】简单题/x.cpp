#include <bits/stdc++.h>
using namespace std;
auto ss(string &s) {
    long long pos=s.find('.');
    if (pos == string::npos) {
        s += ".0";
        pos=s.size()-2;
    }
};
int main() {
    string a,b;
    if (!(cin >> a >> b)) return 0;
    
    ss(a);
    ss(b);
    int p1=a.find('.'),p2=b.find('.');
    string int1=a.substr(0,p1),af=a.substr(p1+1);
    string int2=b.substr(0,p2),bf=b.substr(p2+1);
    int L=max(af.size(),bf.size());
    while (af.size() < L) af.push_back('0');
    while (bf.size() < L) bf.push_back('0');
    string cf(L,'0');
    int tem=0;
    for (int i=L-1; i >= 0; --i) {
        int d=(af[i]-'0')+(bf[i]-'0')+tem;
        cf[i]=char('0'+d % 10);
        tem=d / 10;
    }
    int n1=int1.size(),n2=int2.size();
    int i=n1-1,j=n2-1;
    string ci;
    while (i >= 0||j >= 0||tem) {
        int d=tem;
        if (i >= 0) d += int1[i--]-'0';
        if (j >= 0) d += int2[j--]-'0';
        ci.push_back(char('0'+(d % 10)));
        tem=d / 10;
    }
    while (ci.size() > 1 && ci.back() == '0') ci.pop_back();
    reverse(ci.begin(),ci.end());
    int k=cf.size()-1;
    while (k > 0 && cf[k] == '0') --k;
    cf.resize(k+1);
    cout<<ci<<'.'<<cf;
    return 0;
}