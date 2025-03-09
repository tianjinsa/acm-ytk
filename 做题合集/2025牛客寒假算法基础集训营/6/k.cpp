#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int N;
    cin>>N;
    while(N--){
        int x,y;
        cin>>x>>y;
        if(abs(x*2+1-y)%4==0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
    return 0;
}