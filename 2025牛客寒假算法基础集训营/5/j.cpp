#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    
    cin>>n;
    string str;
    cin>>str; 
    long long v=0,x=0;
    for(int i=0;i<n;i++){
        switch(str[i])
        {
            case '0':
                v+=10;
                x+=v;
                break;
            case '1':
                v=max(v-5,0LL);
                x+=v;
                break;
            case '2':
                int t=v;
                v=max(v-10,0LL);
                x+=v;
                v=t;
                break;
        }
    }
    cout<<x;
    return 0;
}