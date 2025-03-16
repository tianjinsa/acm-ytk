#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a*b==c){
            cout<<"Lv Yan"<<endl;
        }
        else if(a+c==b){
            cout<<"Tu Dou"<<endl;
        }
        else{
            cout<<"zhe du shi sha ya!"<<endl;
        }
    }
    return 0;
}