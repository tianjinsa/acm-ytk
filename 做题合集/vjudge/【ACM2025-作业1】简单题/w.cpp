#include<bits/stdc++.h>
using namespace std;

string t(string s){
    int f=s.find_first_not_of('0');
    if(f==-1)return "0";
    return s.substr(f);
}

bool g(string s1,string s2){
    if(s1.length()>s2.length())return 1;
    if(s1.length()<s2.length())return 0;
    return s1>=s2;
}

string s(string s1,string s2){
    string r="";
    int c=0;
    int i=s1.length()-1;
    int j=s2.length()-1;
    while(i>=0||j>=0){
        int v1=(i>=0)?s1[i]-'0':0;
        int v2=(j>=0)?s2[j]-'0':0;
        int d=v1-v2-c;
        if(d<0){
            d+=10;
            c=1;
        }else{
            c=0;
        }
        r+=(char)(d+'0');
        i--;
        j--;
    }
    reverse(r.begin(),r.end());
    return t(r);
}

string m(string s1,int n){
    if(n==0)return "0";
    string r="";
    int c=0;
    for(int i=s1.length()-1;i>=0;i--){
        int p=(s1[i]-'0')*n+c;
        r+=(char)((p%10)+'0');
        c=p/10;
    }
    while(c>0){
        r+=(char)((c%10)+'0');
        c/=10;
    }
    reverse(r.begin(),r.end());
    return r;
}

string d(string s1,string s2){
    string d1=t(s1);
    string d2=t(s2);
    if(d1=="0")return "0";
    if(!g(d1,d2))return "0";
    string r="";
    string tp="";
    for(char ch:d1){
        tp+=ch;
        tp=t(tp);
        int l=0,h=9,a=0;
        while(l<=h){
            int md=(l+h)/2;
            string p=m(d2,md);
            if(g(tp,p)){
                a=md;
                l=md+1;
            }else{
                h=md-1;
            }
        }
        r+=(char)(a+'0');
        tp=s(tp,m(d2,a));
    }
    return t(r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s1,s2;
    cin>>s1>>s2;
    cout<<d(s1,s2)<<"\n";
    
    return 0;
}
