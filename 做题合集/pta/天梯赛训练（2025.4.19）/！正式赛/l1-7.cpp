#include<bits/stdc++.h>
using namespace std;
int ss(long  long x,long long n){
    int ans=0;
    for(long long i = 1;x>0;++i){
        x-=pow(i,n);
        if(x==0)ans=i;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int ans=0,ansi=0;
    for(long long i=32;i!=0;i--){
        if(ans=ss(n,i)){
            ansi=i;
            break;
        }
    }
    if(!ansi){
        cout << "Impossible for "<<n<<"." << endl;   
        return 0;
    }
    bool fl=0;
    for(int i=1;i<=ans;i++){
        if(fl)cout<<'+';
        fl=1;
        cout<<i<<"^"<<ansi;
    }
    return 0;
}