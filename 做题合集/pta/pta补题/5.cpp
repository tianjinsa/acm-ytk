#include<bits/stdc++.h>
using namespace std;
double ss(set<int> &a,set<int> &b)
{
    double ans=0;
    for(auto i: a){
        if(b.count(i)) ans++;
    }
    return ans/(a.size()+b.size()-ans);
}
int main()
{
    int n;
    cin>>n;
    vector<set<int>> v(n);
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            v[i].insert(x);
        }
    }
    int m;
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--; y--;
        double ans=ss(v[x],v[y]);
        printf("%.2f%%\n", ans*100);
    }
    return 0;
}