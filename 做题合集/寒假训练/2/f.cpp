#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin>>a;
    int t,ans=0,ans2=0;
    for (int i=0;i<a.size();i++) {
        if (a[i]=='b'||a[i + 1]=='o'||a[i + 2]=='y')
            ans++;
        if (a[i]=='g'||a[i + 1]=='i'||a[i + 2]=='r'||a[i + 3]=='l')
            ans2++;
    }
    cout<<ans<<endl<<ans2;
    return 0;
}