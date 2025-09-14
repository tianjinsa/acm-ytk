#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<bool> a(n),b(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c;
            cin>>c;
            bool fl=(c<=50);
            a[j]=fl;
            if(fl!=b[j])
                ans++;
        }
        swap(a,b);
    }
    cout<<ans<<endl;
    return 0;
}