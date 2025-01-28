#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        int S=a+b+c-n;
        if(S<0||S>n){
            cout<<"No\n";
            continue;
        }
        bool fl=0;
        for(int x1=0;x1<=S&&!fl;x1++){
            for(int x3=0;x3<=S-x1&&!fl;x3++){
                int x5=S-x1-x3;
                if(x1+x3<=a&&x3+x5<=b&&x5+x1<=c){
                    cout<<"Yes\n";
                    fl=1;
                }
            }
        }
        if(!fl) cout<<"No\n";
    }
    return 0;
}
