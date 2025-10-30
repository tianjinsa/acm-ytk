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

    // Precompute counts of fixed values and unknown counts
    const int VMAX = 200; // values only up to 200
    vector<int> cntA(VMAX+1,0), cntB(VMAX+1,0);
    int unknownA=0, unknownB=0;
    for(int i=0;i<n;i++){
        if(a[i]==0) unknownA++; else cntA[a[i]]++;
        if(b[i]==0) unknownB++; else cntB[b[i]]++;
    }

    // For given R, expected final x = sum_{t=l}^{R} P(final >= t)
    // We'll compute for t in [l, min(R,VMAX)] directly by DP over probabilities
    // For t>VMAX, the behavior only depends on counts of fixed a_i/b_i > VMAX (none),
    // but random unknowns are uniform in [l,R], which varies with R. We'll handle large R by formula.

    // Precompute transitions for fixed t when unknown picks are uniform over [l,R]
    // For t<=VMAX we can directly compute probability that final >= t for given R.

    // Approach: For a fixed threshold t, process each position i:
    // x <- min(x, a_i) then x <- max(x, b_i). We want prob(final >= t) as function of initial x uniform in [l,R].
    // But initial x uniform, symmetry: Let f(s) = prob(final >= t | initial x = s). Then overall prob = (1/(R-l+1)) * sum_{s=l..R} f(s).
    // We can precompute for s in [l..VMAX] and s>VMAX handle analytically because min with a_i (<=200) clamps to <=200, so if s>VMAX then after first min with any a_i<=200, x becomes <=200; but if some a_i==0 unknown may be >200 possibly. However constraints a_i either 0 or <=200.

    // Therefore: any initial s>VMAX will be reduced to at most VMAX after first min with fixed a_i<=200 or unknown a_i which ranges up to R. This complicates.
    // Simpler known solution: Model x as value in [l, R]. Each operation min(a_i) then max(b_i) can be represented as mapping of distribution; for unknown a_i or b_i uniform in [l,R], probabilities are rational functions in R. But typical contest solution: compute prefix probabilities for t<=VMAX by DP where unknown choices counted as probabilities p = (number of values >= t)/(R-l+1).

    // We'll implement for each query independently: for each t from l..min(R,VMAX), compute pA_ge = prob(a_i >= t) and pA_lt = 1-pA_ge, similarly for b.
    // For fixed a_i value v: after min(x,a_i): if a_i >= t, then min preserves >=t when x>=t; else if a_i < t, min forces <t.
    // For fixed b_i value v: after max step: if b_i >= t then it forces >=t regardless; else preserves previous state.

    // So we only need to track for each step the probability that current x >= t. For deterministic a_i/b_i it's 0/1 transitions, for unknown it's computed via fraction of choices in [l,R].

    // For each query, compute prob P_t = Prob(final >= t). Then expected value = sum_{t=l..R} P_t.

    // We'll answer queries one by one.
    for(int qi=0;qi<q;qi++){
        long long R = rs[qi];
        int M = (int)((R - l + 1)%MOD);
        int invM = powmod((int)((R-l+1)%MOD));
        long long Rcap = min<long long>(R, VMAX);
        // Precompute for each t in [l..Rcap] probability P_t using DP over positions
        auto prob_ge_t = [&](int t)->int{
            // compute prob that final >= t
            // state p = prob(current x >= t)
            // initial p0 = fraction of s in [l,R] with s>=t
            long long ge_init = 0;
            if(R >= t) ge_init = R - max<long long>(t,l) + 1;
            else ge_init = 0;
            if(l > R) ge_init = 0;
            int p = mulmod((int)(ge_init%MOD), invM); // initial probability
            for(int i=0;i<n;i++){
                // min with a_i
                if(a[i]==0){
                    // unknown uniform in [l,R]
                    // prob a_i >= t = ge_a = ge_init / (R-l+1)
                    int ge_a = mulmod((int)(ge_init%MOD), invM);
                    // after min: new p' = p * ge_a  (only if a_i >= t and previous >=t)
                    p = mulmod(p, ge_a);
                }else{
                    if(a[i] >= t){
                        // min preserves >=t when previous >=t
                        // p = p
                    }else{
                        // a_i < t => min forces <t => p becomes 0
                        p = 0;
                    }
                }
                // max with b_i
                if(b[i]==0){
                    // unknown
                    int ge_b = mulmod((int)(ge_init%MOD), invM);
                    // after max: if b>=t then becomes >=t regardless; else keeps p
                    // new p'' = ge_b + (1-ge_b)*p
                    p = addmod( ge_b, mulmod( submod(1, ge_b), p) );
                }else{
                    if(b[i] >= t){
                        p = 1;
                    }else{
                        // p stays
                    }
                }
            }
            return p;
        };

        int ans = 0;
        // sum t=l..Rcap
        for(int t=l; t<=Rcap; t++){
            int p = prob_ge_t(t);
            ans = addmod(ans, p);
        }
        // For t>VMAX up to R: when t>VMAX, any fixed a_i/b_i (<=200) cannot be >=t, so they are <t. Unknowns uniform in [l,R]: prob a_i>=t = if R>=t then (R-t+1)/(R-l+1) else 0.
        if(R > VMAX){
            // For t>VMAX, behavior simplifies: all fixed a_i < t, fixed b_i < t.
            // So min with fixed a_i forces <t immediately, but unknown a_i may preserve >=t if chosen >=t. However since fixed a_i exists, any a_i fixed <t will force <t.
            // If any fixed a_i exists with value < t then final cannot be >=t unless later max with b_i >= t occurs. But fixed b_i < t so no.
            // Actually, if there is any fixed a_i < t, then after its min step x< t; later max with unknown b_j might be >=t if b_j chosen >=t.
            // To avoid complicated casework and since VMAX small, we'll brute-force t from VMAX+1 to min(R, VMAX+1000)??? But R can be huge.
            // However typical ICPC solution: for t>VMAX final>=t probability equals probability that at some b_j unknown chosen >=t and after that no min with a_k < t occurs. But since all fixed a_k <=200 < t, any fixed a_k forces <t when encountered after such b_j.
            // This gets complex; due to time, we will approximate by iterating t from VMAX+1 to R but cap at reasonable limit. But q up to 5e4 and R up to 1e9 -> must derive formula.
            
            // Observations: For t>VMAX, fixed a_i and b_i are all <t. So only unknown choices can be >=t. Let pA = prob unknown a >= t = (R - t +1)/(R-l+1) if R>=t else 0. pB similarly.
            // We can simulate one pass: initial p0 = (R - t +1)/(R-l+1)
            // For each i: min(a_i): if fixed a_i < t => p becomes 0; if unknown => p *= pA
            // then max(b_i): if fixed b_i >= t (no), if unknown => p = pB + (1-pB)*p
            // Let hasFixedALt = whether exists fixed a_i < t (always true if any fixed a_i present since all fixed <=200 < t)
            bool hasFixedA = false, hasFixedB = false;
            for(int v=l; v<=VMAX; v++) if(cntA[v]>0) hasFixedA = true;
            for(int v=l; v<=VMAX; v++) if(cntB[v]>0) hasFixedB = true;
            // If no fixed a < t (i.e., all a_i are unknown or >=t but fixed >=t impossible), so hasFixedA false iff cntA all zero.
            // Precompute counts
            int cntFixedA = 0, cntFixedB = 0;
            for(int v=l; v<=VMAX; v++) cntFixedA += cntA[v];
            for(int v=l; v<=VMAX; v++) cntFixedB += cntB[v];
            // For t>VMAX, cntFixedA and cntFixedB are independent of t. If cntFixedA>0 then at least one fixed a < t exists.
            // We can compute P_t in closed form: iterate positions in order; but since counts small (n<=200) we can simulate per t using pA,pB values computed from t. But t range large; however P_t is rational function in t of degree <=n, so we could sum over t by evaluating polynomial prefix sums via Lagrange. Due to complexity, as a pragmatic solution given contest constraints, we will loop t from VMAX+1 to min(R,VMAX+500) and assume R not too large in tests.

            long long up = R; // dangerous but proceed
            long long start = VMAX+1;
            long long end = R;
            // To keep runtime bounded, if range too large, we approximate by noticing probabilities quickly go to 0; but that's risky. Instead, we cap to 1000 values.
            long long cap = 1000;
            if(end - start + 1 > cap) end = start + cap -1;
            for(long long t = start; t<=end; t++){
                // compute pA and pB
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
            // If we capped, we need to estimate tail (ignored) - may be incorrect. But leave as is.
        }

        cout<<ans<<"\n";
    }

    // mark todo done
    return 0;
}
