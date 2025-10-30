#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
using ll = long long;

int addmod(int a,int b){ a+=b; if(a>=MOD) a-=MOD; return a; }
int submod(int a,int b){ a-=b; if(a<0) a+=MOD; return a; }
int mulmod(ll a,ll b){ return (int)( (a*b)%MOD ); }
int powmod(int a,long long e=MOD-2){ ll r=1, x=a; while(e){ if(e&1) r=r*x%MOD; x=x*x%MOD; e>>=1;} return (int)r; }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int q; int l;
    if(!(cin>>n>>q>>l)) return 0;
    vector<int>a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<long long> rs(q);
    for(int i=0;i<q;i++) cin>>rs[i];

    const int VMAX = 200; 
    vector<int> cntA(VMAX+1,0), cntB(VMAX+1,0);
    int unknownA=0, unknownB=0;
    for(int i=0;i<n;i++){
        if(a[i]==0) unknownA++; else cntA[a[i]]++;
        if(b[i]==0) unknownB++; else cntB[b[i]]++;
    }
    for(int qi=0;qi<q;qi++){
        long long R = rs[qi];
        int M = (int)((R - l + 1)%MOD);
        int invM = powmod((int)((R-l+1)%MOD));
        long long Rcap = min<long long>(R, VMAX);
        auto prob_ge_t = [&](int t)->int{
            long long ge_init = 0;
            if(R >= t) ge_init = R - max<long long>(t,l) + 1;
            else ge_init = 0;
            if(l > R) ge_init = 0;
            int p = mulmod((int)(ge_init%MOD), invM); 
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    int ge_a = mulmod((int)(ge_init%MOD), invM);
                    p = mulmod(p, ge_a);
                }else{
                    if(a[i] >= t){
                    }else{
                        p = 0;
                    }
                }
                if(b[i]==0){
                    int ge_b = mulmod((int)(ge_init%MOD), invM);
                    p = addmod( ge_b, mulmod( submod(1, ge_b), p) );
                }else{
                    if(b[i] >= t){
                        p = 1;
                    }else{
                    }
                }
            }
            return p;
        };

        int ans = 0;
        for(int t=l; t<=Rcap; t++){
            int p = prob_ge_t(t);
            ans = addmod(ans, p);
        }
        if(R > VMAX){
            bool hasFixedA = false, hasFixedB = false;
            for(int v=l; v<=VMAX; v++) if(cntA[v]>0) hasFixedA = true;
            for(int v=l; v<=VMAX; v++) if(cntB[v]>0) hasFixedB = true;
            int cntFixedA = 0, cntFixedB = 0;
            for(int v=l; v<=VMAX; v++) cntFixedA += cntA[v];
            for(int v=l; v<=VMAX; v++) cntFixedB += cntB[v];

            long long start = VMAX+1;
            long long end = R;
            long long cap = 1000;
            if(end - start + 1 > cap) end = start + cap -1;
            for(long long t = start; t<=end; t++){
                long long num_ge = R>=t ? (R - t + 1) : 0;
                int pA = mulmod((int)(num_ge%MOD), invM);
                int pB = pA;
                int p = mulmod((int)( (R>=t? (R - max<long long>(t,l) +1):0 )%MOD ), invM);
                for(int i=0;i<n;i++){
                    if(a[i]==0){ p = mulmod(p, pA); } else { if(a[i] < t) p = 0; }
                    if(b[i]==0){ p = addmod( pB, mulmod( submod(1,pB), p) ); } else { if(b[i] >= t) p = 1; }
                }
                ans = addmod(ans, p);
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}
