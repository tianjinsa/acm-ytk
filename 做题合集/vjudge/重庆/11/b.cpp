#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector<string> S(N);
    for(int i=0;i<N;++i)
        cin>>S[i];
    unordered_set<string> st;
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            if(i!=j) st.insert(S[i]+S[j]);
    cout<<st.size();
    return 0;
}