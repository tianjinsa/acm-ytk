#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    set<long long> st;
    for(int i=0;i<n;i++)
    {
        int op;
        long long x;
        cin>>op>>x;
        if(op==1)
        {
            if(st.count(x))
            {
                cout<<"Already Exist\n";
            }
            else
            {
                st.insert(x);
            }
        }
        else if(op==2)
        {
            if(st.empty())
            {
                cout<<"Empty\n";
            }
            else
            {
                auto it=st.lower_bound(x);
                if(it!=st.end()&&*it==x)
                {
                    cout<<x<<"\n";
                    st.erase(it);
                }
                else
                {
                    long long cand;
                    if(it==st.begin())
                    {
                        cand=*it;
                    }
                    else if(it==st.end())
                    {
                        cand=*prev(it);
                    }
                    else
                    {
                        auto pit=prev(it);
                        long long hi=*it;
                        long long lo=*pit;
                        long long dhi=llabs(hi-x);
                        long long dlo=llabs(lo-x);
                        if(dhi<dlo)
                            cand=hi;
                        else
                            cand=lo;
                    }
                    cout<<cand<<"\n";
                    st.erase(cand);
                }
            }
        }
    }

    return 0;
}