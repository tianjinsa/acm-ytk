#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==2||b==1){
        cout<<"-"<<endl;
    }
    else if(a==0){
        cout<<"biii"<<endl;
    }
    else if(a==1){
        cout<<"dudu"<<endl;
    }
    if(a==0||a==2){
        cout<<"stop"<<endl;
    }
    else if(a==1){
        cout<<"move"<<endl;
    }
    
    return 0;
}