#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string add(string a,string b)
{
    string res;
    int i=a.size()-1,j=b.size()-1,carry=0;
    while(i >= 0||j >= 0||carry)
    {
        int sum=carry;
        if(i >= 0)
            sum += a[i--]-'0';
        if(j >= 0)
            sum += b[j--]-'0';
        res.push_back(char('0'+sum % 10));
        carry=sum/10;
    }
    reverse(res.begin(),res.end());
    return res;
}

string sub(string a,string b)
{
    if(a==b)
        return "0";
    bool neg=false;
    if(a.size()<b.size()||(a.size()==b.size()&&a<b))
    {
        swap(a,b);
        neg=true;
    }
    int i=a.size()-1,j=b.size()-1,borrow=0;
    string res;
    while(i >= 0)
    {
        int d=a[i]-'0'-borrow -(j >= 0?b[j]-'0':0);
        borrow=0;
        if(d<0)
        {
            d += 10;
            borrow=1;
        }
        res.push_back(char('0'+d));
        i--;
        j--;
    }
    while(res.size()>1&&res.back()=='0')
        res.pop_back();
    if(neg)
        res.push_back('-');
    reverse(res.begin(),res.end());
    return res;
}

string mul(string a,string b)
{
    if(a=="0"||b=="0")
        return "0";
    int n=a.size(),m=b.size();
    vector<int> c(n+m);
    for(int i=n-1;i >= 0;--i)
        for(int j=m-1;j >= 0;--j)
            c[i+j+1] +=(a[i]-'0') *(b[j]-'0');
    for(int k=n+m-1;k>0;--k)
    {
        c[k-1] += c[k] / 10;
        c[k] %= 10;
    }
    string res;
    int p=0;
    while(p<c.size()&&c[p]==0)
        p++;
    for(;p<c.size();++p)
        res.push_back(char('0'+c[p]));
    return res;
}

pair<string,string> divmod(string a,string b)
{
    if(b=="0")
        return {"0","0"};
    string quotient,current;
    for(char ch:a)
    {
        current.push_back(ch);
        while(current.size()>1&&current[0]=='0')
            current.erase(current.begin());
        int x=0,l=0,r=9;
        while(l<=r)
        {
            int mid =(l+r)/2;
            string t=mul(b,to_string(mid));
            if(t.size()<current.size()||(t.size()==current.size()&&t<=current))
            {
                x=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        quotient.push_back(char('0'+x));
        current=sub(current,mul(b,to_string(x)));
        if(current[0]=='-')
            current="0";
    }
    while(quotient.size()>1&&quotient[0]=='0')
        quotient.erase(quotient.begin());
    if(quotient.empty())
        quotient="0";
    if(current.empty())
        current="0";
    return {quotient,current};
}

int main()
{
    string a,b;
    cin >> a >> b;
    cout<<add(a,b)<<'\n';
    cout<<sub(a,b)<<'\n';
    cout<<mul(a,b)<<'\n';
    auto [q,r]=divmod(a,b);
    cout<<q<<'\n'<<r<<'\n';
    return 0;
}