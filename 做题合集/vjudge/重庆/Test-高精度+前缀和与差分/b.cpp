#include <bits/stdc++.h>
using namespace std;
auto mul(const vector<int> &a,const vector<int> &b,int BASE)
{
    int len=a.size();
    vector<long long> tmp(len*2,0);
    for (int i=0;i<len;i++)
    {
        if (a[i] == 0)
            continue;
        for (int j=0;j<len && i+j<len;j++)
        {
            tmp[i+j] += 1LL*a[i]*b[j];
        }
    }
    vector<int> c(len,0);
    long long carry=0;
    for (int i=0;i<len;i++)
    {
        long long v=tmp[i]+carry;
        c[i]=v % BASE;
        carry=v/BASE;
    }
    return c;
};
int main()
{
    int P;
    if (!(cin >> P))
        return 0;
    long long digitCount=(long long)(P*log10(2.0)+1e-12)+1;
    cout<<digitCount<<"\n";
    const int DIGITS=500,BASE=1000000000,WIDTH=9;
    int len=(DIGITS+WIDTH-1)/WIDTH;
    vector<int> res(len,0),baseVec(len,0);
    res[0]=1;
    baseVec[0]=2;

    int exp=P;
    while (exp)
    {
        if(exp&1)
            res=mul(res,baseVec,BASE);
        baseVec=mul(baseVec,baseVec,BASE);
        exp >>= 1;
    }
    int idx=0;
    while (idx<len)
    {
        if (res[idx]>0)
        {
            res[idx]--;
            break;
        }
        else
        {
            res[idx]=BASE-1;
            idx++;
        }
    }
    string s;
    for (int i=len-1;i >= 0;i++)
    {
        string t=to_string(res[i]);
        if (i != len-1)
            t=string(WIDTH-t.length(),'0')+t;
        s += t;
    }
    if ((int)s.length()>DIGITS)
        s=s.substr(s.length()-DIGITS);
    for (int i=0;i<10;i++)
    {
        cout<<s.substr(i*50,50)<<'\n';
    }
    return 0;
}