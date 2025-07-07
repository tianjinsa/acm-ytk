#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int Q;
    cin>>Q;
    multiset<long long> st;
    while(Q--)
    {
        int c;
        long long x;
        int k;
        cin>>c;
        if(c==1)
        {
            cin>>x;
            st.insert(x);
        }
        else if(c==2)
        {
            cin>>x>>k;
            auto it=st.upper_bound(x);
            bool ok=true;
            for(int i=0;i<k;i++)
            {
                if(it==st.begin())
                {
                    ok=false;
                    break;
                }
                --it;
            }
            if(ok)
                cout<<*it<<"\n";
            else
                cout<<-1<<"\n";
        }
        else
        {
            cin>>x>>k;
            auto it=st.lower_bound(x);
            bool ok=true;
            for(int i=1;i<k;i++)
            {
                if(it==st.end())
                {
                    ok=false;
                    break;
                }
                ++it;
            }
            if(it==st.end())
                ok=false;
            if(ok)
                cout<<*it<<"\n";
            else
                cout<<-1<<"\n";
        }
    }
    return 0;
}