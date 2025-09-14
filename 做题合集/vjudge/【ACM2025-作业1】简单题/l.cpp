#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin>>k;
    while(k--){
        string s;
        double w,r,g,t,p;
        cin>>s>>w>>r>>g>>t>>p;
        int c=0;
        if(w<4.0||w>10.0){
            c++;
        }
        if(r<3.5||r>5.5){
            c++;
        }
        if(s=="male"){
            if(g<120||g>160){
                c++;
            }
            if(t<42||t>48){
                c++;
            }
        }else{
            if(g<110||g>150){
                c++;
            }
            if(t<36||t>40){
                c++;
            }
        }
        if(p<100||p>300){
            c++;
        }
        if(c==0){
            cout<<"normal\n";
        }else{
            cout<<c<<"\n";
        }
    }
    return 0;
}
