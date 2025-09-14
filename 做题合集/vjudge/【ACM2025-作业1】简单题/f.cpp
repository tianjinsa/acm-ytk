#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int minn=0,maxx=0;
        for(int i=0;i<m;i++){
            int a;
            cin>>a;
            if(a>n-a)a=n-a;
            minn=max(minn,a);
            maxx=max(maxx,n-a);
        }
        cout<<minn<<' '<<maxx<<'\n';
    }
    return 0;
}