#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int M,N,A,B;
    cin>>M>>N>>A>>B;
    vector<string> G(M);
    for(int i=0;i<M;i++)
        cin>>G[i];
    int Q;
    cin>>Q;
    const unsigned long long base1=(1ULL<<7)-1,base2=(1ULL<<13)-1;
    vector<unsigned long long> p1(B+1),p2(A+1);
    p1[0]=1;
    for(int i=1;i<=B;i++)
        p1[i]=p1[i-1]*base1;
    p2[0]=1;
    for(int i=1;i<=A;i++)
        p2[i]=p2[i-1]*base2;
    vector<vector<unsigned long long>> r(M,vector<unsigned long long>(N-B+1));
    for(int i=0;i<M;i++){
        unsigned long long h=0;
        for(int j=0;j<N;j++){
            h=h*base1+(G[i][j]-'0'+1);
            if(j>=B) h -= p1[B]*(G[i][j-B]-'0'+1);
            if(j>=B-1) r[i][j-B+1]=h;
        }
    }
    int MA=M-A+1;
    unordered_set<unsigned long long> S;
    for(int j=0;j<N-B+1;j++){
        unsigned long long h=0;
        for(int i=0;i<M;i++){
            h=h*base2+r[i][j];
            if(i>=A) h-=p2[A]*r[i-A][j];
            if(i>=A-1) S.insert(h);
        }
    }
    string s;
    vector<unsigned long long> tc(A);
    while(Q--){
        for(int i=0;i<A;i++){
            cin>>s;
            unsigned long long h=0;
            for(int j=0;j<B;j++) h=h*base1+(s[j]-'0'+1);
            tc[i]=h;
        }
        unsigned long long h=0;
        for(int i=0;i<A;i++) h=h*base2+tc[i];
        cout<<(S.count(h)?'1':'0')<<'\n';
    }
    return 0;
}