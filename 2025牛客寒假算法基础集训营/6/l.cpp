#include<bits/stdc++.h>
using namespace std;
bool sss(string s){
    string tt="CHICKEN";
    int t=0;
    for(char c:tt){
        t=s.find(c,t);
        if(t==-1){
            return 0;
        }
        t=t+1;
    }
    return 1;
}
int main()
{
    
    int N;
    cin >> N;
    while(N--){
        int n;
        string s;
        cin >> n >> s;
        bool fl=1;
        if((n-7)%2==0&&sss(s)){
            int a[26] ={0};
            for(char c:s){
                a[c-'A']++;
            }
            a['C'-'A']-=2;
            a['H'-'A']--;
            a['I'-'A']--;
            a['K'-'A']--;
            a['E'-'A']--;
            a['N'-'A']--;
            int max=0;
            for(auto c:a){
                if(c>max)
                    max=c;
            }
            if(max>(n-7)/2){
                fl=0;
            }
        }
        else{
            fl=0;
        }
        if(fl){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}