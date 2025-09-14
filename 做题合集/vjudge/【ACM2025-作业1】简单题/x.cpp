#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    if (!(cin >> a >> b)) return 0;
    auto normalize=[&](string &s) {
        size_t pos=s.find('.');
        if (pos == string::npos) {
            s += ".0";
            pos=s.size()-2;
        }
    };
    normalize(a);
    normalize(b);
    int p1=a.find('.'),p2=b.find('.');
    string int1=a.substr(0,p1),frac1=a.substr(p1+1);
    string int2=b.substr(0,p2),frac2=b.substr(p2+1);
    int L=max(frac1.size(),frac2.size());
    while (frac1.size() < L) frac1.push_back('0');
    while (frac2.size() < L) frac2.push_back('0');
    string resFrac(L,'0');
    int carry=0;
    for (int i=L-1; i >= 0; --i) {
        int d=(frac1[i]-'0')+(frac2[i]-'0')+carry;
        resFrac[i]=char('0'+d % 10);
        carry=d / 10;
    }
    int n1=int1.size(),n2=int2.size();
    int i=n1-1,j=n2-1;
    string resInt;
    while (i >= 0 || j >= 0 || carry) {
        int d=carry;
        if (i >= 0) d += int1[i--]-'0';
        if (j >= 0) d += int2[j--]-'0';
        resInt.push_back(char('0'+(d % 10)));
        carry=d / 10;
    }
    while (resInt.size() > 1 && resInt.back() == '0') resInt.pop_back();
    reverse(resInt.begin(),resInt.end());
    int k=resFrac.size()-1;
    while (k > 0 && resFrac[k] == '0') --k;
    resFrac.resize(k+1);
    cout << resInt << '.' << resFrac;
    return 0;
}