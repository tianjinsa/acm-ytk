#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a%2>b%2;
}
int main()
{
    vector<int> a(1);
    int t;
    cin>>a[0];
    char c;
    while(cin>>c>>t)
    {
        a.push_back(t);
    }
    sort(a.begin(),a.end(),cmp);
    cout<<a[0];
    for(int i=1;i<a.size();i++)
    {
        cout<<","<<a[i];
    }
    return 0;
}