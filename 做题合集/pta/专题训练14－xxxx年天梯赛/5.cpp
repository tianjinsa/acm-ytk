#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[4],min,dx,maxx=0;
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>min>>dx;
    stack<int> s;
    for(int i=0;i<4;++i){
        if(a[i]>maxx){
            maxx=a[i];
        }
    }
    for(int i=0;i<4;++i){
        if(a[i]<min||maxx-a[i]>dx){
            s.push(i+1);
        }
    }
    if(s.empty()){
        cout<<"Normal";
    }
    else if(s.size()==1){
        cout<<"Warning: please check #"<<s.top()<<"!";
    }
    else{
        cout<<"Warning: please check all the tires!";
    }
    return 0;
}