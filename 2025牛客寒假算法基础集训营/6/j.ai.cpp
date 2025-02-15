#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while(T--){
        long long n,x,y;
        cin >> n >> x >> y;
        if(y*2+x<=n){
            cout<<(y+x)*(y+x+1)/2<<endl;
            continue;
        }
        if(y>=n){
            cout<<(n+x+1)*(n+x+1)/4<<endl;
            continue;
        }
        long long s=max(0LL,min(n-y-x,y));
        long long part1=(y-s)*(x+s+1);
        long long R=n-y;
        long long part2=R*(2*(x+s)-R+1)/2;
        cout<<part1+part2<<endl;
    }

    return 0;
}