#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a[n+1]={0};
        for (int i=0;i<n;i++){
            a[i+1]=a[i]+(s[i]=='u');
        }
        long long ans=0;
        int pos=0;
        while(true){
            pos=s.find("uwawauwa",pos);
            if(pos==-1) break;
            ans+=a[pos];
            if(s[pos]=='u')ans--;
            pos++;
        }
        cout<<ans<<endl;
    }
    return 0;
}