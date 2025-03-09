#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    while(N--){
        int a[8][2]={0},b=0;
        char t;
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                cin>>t;
                switch(t)
                {
                    case 'O':
                        a[i][1]++;
                        a[j+3][1]++;
                        if(i+j==2){
                            a[6][1]++;
                        }
                        if(i==j){
                            a[7][1]++;
                        }
                        break;
                    case 'X':
                        a[i][0]++;
                        a[j+3][0]++;
                        if(i+j==2){
                            a[6][0]++;
                        }
                        if(i==j){
                            a[7][0]++;
                        }
                        break;
                    default:
                        b++;
                        break;
                }
            }
        }
        bool fl=0;
        int tt=0;
        for(auto &c:a){
            if(c[0]==0&&c[1]==0)
                tt++;
            if((c[0]>=1&&c[1]==0)||b==9||tt>=2){
                fl=1;
                break;
            }
            
        }
        if(fl){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}