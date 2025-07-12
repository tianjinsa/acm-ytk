#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int ans=INT_MIN;
    vector<int> temp(n);
    for(int top=0;top<n;top++)
    {
        temp.assign(n,0);
        for(int i=top;i<n;i++)
        {
            for(int j=0;j<n;j++)
                temp[j]+=a[i][j];
            int sum=0;
            for(int k=0;k<n;k++)
            {
                sum=max(temp[k],sum+temp[k]);
                ans=max(ans,sum);
            }
        }
    }
    cout << ans;
    return 0;
}