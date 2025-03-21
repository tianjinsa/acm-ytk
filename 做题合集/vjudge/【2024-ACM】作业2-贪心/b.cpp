#include<bits/stdc++.h>
using namespace std;
void ss(string &s){
    for(int i=0;i<s.size()-1;i++){
        if(s[i]>s[i+1]){
            s.erase(i,1);
            i--;
            return;
        }
    }
    s.erase(s.size()-1,1);
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        string s;
        int k;
        cin>>s>>k;
        while(k--){
            ss(s);
        }
        cout<<s<<endl;
    }
    
    return 0;
}