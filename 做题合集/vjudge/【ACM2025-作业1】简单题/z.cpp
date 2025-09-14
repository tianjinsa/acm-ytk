#include<bits/stdc++.h>
using namespace std;

int ss(int m,int Y)
{
    if(m==2){
        return ((Y%4==0&&Y%100!=0)||(Y%400==0))?29:28;
    }
    if(m==4||m==6||m==9||m==11){
        return 30;
    }
    return 31;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int Y,M,d;
    char s;
    
    while(cin>>Y>>s>>M>>s>>d){
        int ans=0;
        for(int i=1;i<M;++i){
            ans+=ss(i,Y);
        }
        ans+=d;
        cout<<ans<<"\n";
    }
    
    return 0;
}
