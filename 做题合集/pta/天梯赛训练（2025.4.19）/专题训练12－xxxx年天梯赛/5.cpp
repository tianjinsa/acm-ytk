#include<bits/stdc++.h>
using namespace std;
int sum(int x){
    string s=to_string(x);
    int all=0;
    for(char c:s){
        all+=c-'0';
    }
    return all;
}
int ss(int x){
    int ans=sum(x*2);
    for(int i=3;i<=9;i++){
        if(ans!=sum(x*i))return 0;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        int t=ss(x);
        if(t){
            cout<<t<<'\n';
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}