#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    string s1[]={
        "012210",
        "021120",
        "201102"};
    string s2[]={
        "210012",
        "120021",
        "102201",
        "012210",
        "021120",
        "201102"};
    int T ;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        if((n==4&&m>6)||(m==4&&n>6)){
            bool fl=(n==4);
            if(fl)swap(n,m);
            vector<string> a(n);
            string ss1[]={
                "2101",
                "1201",
                "1022"
            };
            string ss2[]={
                "0122",
                "0211",
                "2010"
            };
            string ss12[]={
                "2100",
                "1200",
                "1022"
            };
            string ss22[]={
                "0122",
                "0211",
                "2011"
            };
            if((n/3)%2==1){
                for(int i=0;i<n/3-2;i++){
                    for(int j=0;j<3;j++){
                        if((i)%2==0)
                            a[i*3+j]=ss12[j];
                        else
                            a[i*3+j]=ss22[j];
                    }
                }
                a[n-6]=ss2[0];
                a[n-5]=ss2[1];
                a[n-4]=ss2[2];
                a[n-3]=ss1[0];
                a[n-2]=ss1[1];
                a[n-1]=ss1[2];
            }
            else{
                for(int i=0;i<n/3;i++){
                    for(int j=0;j<3;j++){
                        if((i)%2==0)
                            a[i*3+j]=ss12[j];
                        else
                            a[i*3+j]=ss22[j];
                    }
                }
            }
            if(fl)
            swap(n,m);
            cout<<"Yes\n";
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(fl)cout<<a[j][i];
                    else cout<<a[i][j];
                }
                cout<<"\n";
            }
            continue;
        }
        if(n==6&&m==1){
            cout<<"Yes\n";
            cout<<"0\n0\n1\n1\n2\n2\n";
            continue;
        }
        if(n==1&&m==6){
            cout<<"Yes\n";
            cout<<"001122\n";
            continue;
        }
        if(n==2&&m==6){
            cout<<"Yes\n";
            cout<<"001122\n";
            cout<<"001122\n";
            continue;
        }
        if(n==6&&m==2){
            cout<<"Yes\n";
            cout<<"00\n00\n11\n11\n22\n22\n";
            continue;
        }
        if(n <= 2){
            if(m == 3){
                cout << "Yes" << endl;
                for(int i = 0 ;i < n;i ++){
                    for(int j = 0;j < 3;j ++){
                        cout << j ;
                    }
                    cout << endl;
                }
    
            }else{
                cout <<"No" << endl;
            }
            continue;
        }
    
        if(m <= 2){
            if(n == 3){
                cout << "Yes" << endl;
                for(int i = 0;i < 3;i ++){
                    for(int j = 0;j < m;j ++){
                        cout << i;
                    }
                    cout << endl;
                }
    
            }else{
                cout <<"No" << endl;
            }
            continue;
        }
        cout<<"Yes\n";
        bool fl=m%3||n==3;
        if(fl)swap(n,m);
        vector<string> a(3*(n+2)/3);
        for(int i=0;i<3;i++)
            for(int j=0;j<(m+5)/6;j++)
                a[i]+=s1[i];
        for(int i=3;i<3*(n+2)/3;i++){
            for(int j=0;j<(m+5)/6;j++)
                a[i]+=s2[(i-3)%6];
        }
        if(fl)
        swap(n,m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(fl)cout<<a[j][i];
                else cout<<a[i][j];
            }
            cout<<"\n";
        }
    }

    return 0;
}