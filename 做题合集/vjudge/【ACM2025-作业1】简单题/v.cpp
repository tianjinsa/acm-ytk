#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string a,b;
    cin>>a>>b;
    
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    
    string r;
    int c=0;
    int n1=a.size();
    int n2=b.size();
    
    for(int i=0;i<n1;++i){
        int d1=a[i]-'0';
        int d2=(i<n2)?(b[i]-'0'):0;
        
        int d=d1-d2-c;
        
        if(d<0){
            d+=10;
            c=1;
        }
        else{
            c=0;
        }
        r.push_back((char)(d+'0'));
    }
    
    while(r.size()>1&&r.back()=='0'){
        r.pop_back();
    }
    
    reverse(r.begin(),r.end());
    
    cout<<r<<endl;
    
    return 0;
}
