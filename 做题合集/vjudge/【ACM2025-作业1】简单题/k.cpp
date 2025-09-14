#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a,b;
    while(cin>>a>>b&&(a||b)){
        int c=0;
        int r=0;
        while(a||b||c){
            if((a%10)+(b%10)+c>=10){
                r++;
                c=1;
            }
            else{
                c=0;
            }
            a/=10;
            b/=10;
        }
        if(r==0){
            cout<<"No carry operation.\n";
        }
        else if(r==1){
            cout<<"1 carry operation.\n";
        }
        else{
            cout<<r<<" carry operations.\n";
        }
    }
    return 0;
}
