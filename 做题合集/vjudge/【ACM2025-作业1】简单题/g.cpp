#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k,caseNum=0;
    while(cin>>n>>k&&(n||k)){
        vector<pair<int,int>>aa;
        for(int i=0;i<k;i++){
            int x,y;
            cin>>x>>y;
            aa.push_back({x-1,y-1});
        }
        vector<int> bb(n,0);
        int maxx=0;
        for(int i=0;i<k;i++){
            auto&[x,y]=aa[i];
            int t=max(bb[x],bb[y])+1;
            bb[x]=t;
            bb[y]=t;
            maxx=max(maxx,t);
        }
        bool fl=1;
        int all=1<<n;
        vector<int> a(n);
        for(int mask=0;mask<all;mask++){
            for(int i=0;i<n;i++)
                a[i]=(mask>>i)&1;
            for(auto &[x,y]:aa){
                if(a[x]>a[y])
                    swap(a[x],a[y]);
            }
            for(int i=1;i<n;i++){
                if(a[i-1]>a[i]){
                    fl=0;
                    break;
                }
            }
            if(!fl)
                break;
        }
        cout<<"Case "<<++caseNum<<" is ";
        if(!fl)
            cout<<"not ";
        cout<<"a sorting network and operates in "<<maxx<<" time units.\n";
    }
    return 0;
}