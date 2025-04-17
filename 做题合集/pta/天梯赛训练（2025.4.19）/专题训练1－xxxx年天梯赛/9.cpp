#include<bits/stdc++.h>
using namespace std;
vector<set<int>> a;
double ss(int &x,int &y){
    set<int>com=a[x];
    for(auto i:a[y]){
        com.insert(i);
    }
    return (double)(a[x].size()+a[y].size()-com.size())/com.size()*100;
}
int main()
{
    int n;
    cin>>n;
    a.resize(n);
    while(n--){
        int m,t;
        cin>>m;
        set<int> b;
        for(int i=0;i<m;i++){
            cin>>t;
            b.insert(t);
        }
        a[a.size()-n-1]=b;
    }
    cin>>n;
    while(n--){
        int x,y;
        cin>>x>>y;
        printf("%.2lf%%\n",ss(--x,--y));
    }
    return 0;
}