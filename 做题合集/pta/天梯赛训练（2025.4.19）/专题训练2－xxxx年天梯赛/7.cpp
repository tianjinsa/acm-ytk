#include<bits/stdc++.h>
using namespace std;
long long ss(long long a){
    if(a<10)return 0;
    long long nn=1;
    while(a!=0){
        nn*=a%10;
        a/=10;
    }
    return 1+(nn>9?ss(nn):0);
}
int main()
{
    long long a,b;
    cin>>a>>b;
    long long max=0;
    set<long long> s;
    for(long long i=a;i<=b;i++){
        long long t=ss(i);
        if(t>max){
            max=t;
            s.clear();
        }
        if(t==max){
            s.insert(i);
        }
    }
    cout<<max<<endl;
    for(long long num:s){
        if(num!=*s.begin())cout<<" ";
        cout<<num;
    }
    return 0;
}