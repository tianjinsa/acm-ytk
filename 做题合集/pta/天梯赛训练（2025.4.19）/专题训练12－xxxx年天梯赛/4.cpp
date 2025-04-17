#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        bool fl;
        int h,w;
        cin>>fl>>h>>w;
        if(fl){
            h-=130;
            w-=27;
        }
        else{
            h-=129;
            w-=25;
        }
        if(h>0){
            cout<<"ni li hai! ";
        }
        else if(h==0){
            cout<<"wan mei! ";
        }
        else{
            cout<<"duo chi yu! ";
        }
        if(w>0){
            cout<<"shao chi rou!\n";
        }
        else if(w==0){
            cout<<"wan mei!\n";
        }
        else{
            cout<<"duo chi rou!\n";
        }
    }
    return 0;
}