#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    while(n--){
        int a,b;
        string sa,sb,t;
        cin>>a>>b>>sa>>sb;

        t=s.substr(a-1,b-a+1);
        s.erase(a-1,b-a+1);
        sb=sa+sb;
        if(s.find(sb)==-1){
            s+=t;
            continue;
        }
        s.insert(s.find(sb)+sa.size(),t);
        
    }
    cout<<s;
    return 0;
}