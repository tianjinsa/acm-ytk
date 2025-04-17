#include<bits/stdc++.h>
using namespace std;

int main()
{
    int min,xx,a,b;
    cin>>min>>xx>>a>>b;
    bool fl1=(a>=min)||(b>=xx);
    bool fl2=(b>=min)||(a>=xx);
    cout<<a<<(fl1?"-Y":"-N")<<" "<<b<<(fl2?"-Y":"-N")<<endl;
    if(fl1&&fl2){
        if((a<min&&b>=xx)||(b<min&&a>=xx)){
            if(a<min&&b>=xx){
                cout<<"qing 2 zhao gu hao 1"<<endl;
            }
            else{
                cout<<"qing 1 zhao gu hao 2"<<endl;
            }
        }
        else{
            cout<<"huan ying ru guan"<<endl;
        }
    }
    else if(!fl1&&!fl2){
        cout<<"zhang da zai lai ba"<<endl;
    }
    else{
        if(fl1){
            cout<<"1: huan ying ru guan"<<endl;
        }
        else{
            cout<<"2: huan ying ru guan"<<endl;
        }
    }
    
    return 0;
}