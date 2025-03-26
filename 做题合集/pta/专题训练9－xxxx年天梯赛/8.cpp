#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a,b,c;
int ra,ca,rb,cb;
int ss(int ax,int bx)
{
    int sum=0;
    for(int i=0;i<ca;i++)
    {
        sum+=a[ax][i]*b[i][bx];
    }
    return sum;
}
int main()
{
    
    cin>>ra>>ca;
    a.resize(ra,vector<int>(ca));
    for(int i=0;i<ra;i++){
        for(int j=0;j<ca;j++){
            cin>>a[i][j];
        }
    }
    cin>>rb>>cb;
    b.resize(rb,vector<int>(cb));
    for(int i=0;i<rb;i++){
        for(int j=0;j<cb;j++){
            cin>>b[i][j];
        }
    }
    
    if(ca!=rb){
        cout<<"Error: "<<ca<<" != "<<rb;
        return 0;
    }
    c.resize(ra,vector<int>(cb));
    
    for(int i=0;i<ra;i++){
        for(int j=0;j<cb;j++){
            c[i][j]=ss(i,j);
        }
    }
    cout<<ra<<' '<<cb<<endl;
    for(int i=0;i<ra;i++){
        for(int j=0;j<cb-1;j++){
            cout<<c[i][j]<<' ';
        }
        cout<<c[i][cb-1]<<endl;
    }
    return 0;
}