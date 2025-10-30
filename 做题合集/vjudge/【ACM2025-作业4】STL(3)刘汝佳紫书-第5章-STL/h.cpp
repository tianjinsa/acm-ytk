#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<string> names;
    while(cin>>n){
        names.clear();
        int maxl=0;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            names.push_back(s);
            maxl=max(maxl,(int)s.length());
        }
        sort(names.begin(),names.end());
        cout<<string(60,'-')<<"\n";
        int wi=(60-maxl)/(maxl+2)+1;
        wi=min(wi,n);
        int R=(n+wi-1)/wi;
        for(int i=0;i<R;i++){
            for(int j=0;j<wi;j++){
                int idx=j*R+i;
                if(idx<n){
                    cout<<setw((j == wi-1)?maxl:(maxl+2))<<left<<names[idx];
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}