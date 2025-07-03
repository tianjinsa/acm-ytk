#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n,0));
    a[0][n/2]=1;
    int tx=0,ty=n/2;
    for(int i=2;i<=n*n;i++)
    {
        if(tx==0&&ty!=n-1)
        {
            tx=n-1;
            ty++;
        }
        else if(tx!=0&&ty==n-1)
        {
            tx--;
            ty=0;
        }
        else if(tx==0&&ty==n-1)
        {
            tx++;
        }
        else
        {
            if(a[tx-1][ty+1]==0)
            {
                tx--;
                ty++;
            }
            else
            {
                tx++;
            }
        }
        a[tx][ty]=i;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}